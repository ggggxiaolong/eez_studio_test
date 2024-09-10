#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/ui/ui.h"

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

    /*Handle LVGL tasks*/
    while(1) {
        lv_timer_handler();
        ui_tick();
        usleep(5000);
    }

    return 0;
}
