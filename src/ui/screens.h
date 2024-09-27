#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *home;
    lv_obj_t *meter;
    lv_obj_t *tabscreen;
    lv_obj_t *address;
    lv_obj_t *bar_chart;
    lv_obj_t *bar_chart_container;
    lv_obj_t *bar_scale;
    lv_obj_t *chart_wrapper;
    lv_obj_t *line_chart;
    lv_obj_t *line_chart2;
    lv_obj_t *line_chart3;
    lv_obj_t *line_chart4;
    lv_obj_t *list;
    lv_obj_t *lv_img_junray;
    lv_obj_t *lv_input;
    lv_obj_t *lv_lottie;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *qr_code_parent;
    lv_obj_t *table;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_HOME = 2,
    SCREEN_ID_METER = 3,
    SCREEN_ID_TABSCREEN = 4,
};

void create_screen_main();
void tick_screen_main();

void create_screen_home();
void tick_screen_home();

void create_screen_meter();
void tick_screen_meter();

void create_screen_tabscreen();
void tick_screen_tabscreen();

void init_keyboard();
static void hook_division_lines(lv_event_t * e);
static void add_faded_area(lv_event_t * e);
static void draw_event_cb(lv_event_t * e);
void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/