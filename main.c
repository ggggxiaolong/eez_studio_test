#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/ui/ui.h"
#include <sqlite3.h>
#include "MQTTClient.h"

#define ADDRESS     "tcp://221.215.132.218:28183"
#define CLIENTID    "eezstudio"
#define TOPIC       "device/linux"
#define PAYLOAD     "Hello World!"
#define QOS         1
#define TIMEOUT     10000L

int main(void)
{
    lv_init();

    /*Linux display device init*/
    // lv_linux_disp_init();

    lv_display_t * disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");

    // 创建一个鼠标输入设备
    lv_indev_t *mouse = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event0");
    // 将鼠标输入设备设置到显示器上
    lv_indev_set_display(mouse, disp);
    
    /*Create a Demo*/
    // lv_demo_widgets();
    // lv_demo_widgets_start_slideshow();
    ui_init();
    printf("%s\n", sqlite3_libversion());

    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;
 
    if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to create client, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }
 
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
 
    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = (int)strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    if ((rc = MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to publish message, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }
 
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
 
    if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
        printf("Failed to disconnect, return code %d\n", rc);
    MQTTClient_destroy(&client);

    /*Handle LVGL tasks*/
    while(1) {
        lv_timer_handler();
        ui_tick();
        usleep(5000);
    }

    return 0;
}
