#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"
#include "lottie.h"
#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 3, 3, value, "Failed to assign Value in Arc widget");
            }
        }
    }
}

static void event_handler_cb_main_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_main_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 10, 3, value, "Failed to assign Selected in Dropdown widget");
            }
        }
    }
}

static void event_handler_cb_main_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 11, 3, value, "Failed to assign Selected in Roller widget");
            }
        }
    }
}

static void event_handler_cb_main_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 13, 3, value, "Failed to assign Value in Slider widget");
            }
        }
    }
}

static void event_handler_cb_main_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
}

static void event_handler_cb_home_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_home_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_meter_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_meter_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 13, 10);
            lv_obj_set_size(obj, 160, 160);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 59, 58);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 10, 10);
                    lv_obj_set_size(obj, 140, 140);
                    lv_arc_set_range(obj, 0, 99);
                    lv_arc_set_bg_end_angle(obj, 60);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 173, 16);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj2, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Home");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_buttonmatrix_create(parent_obj);
            lv_obj_set_pos(obj, 307, 16);
            lv_obj_set_size(obj, 215, 50);
            static const char *map[3] = {
                "Btn1",
                "Btn2",
                NULL,
            };
            static lv_buttonmatrix_ctrl_t ctrl_map[2] = {
                1 | LV_BUTTONMATRIX_CTRL_CHECKABLE,
                1 | LV_BUTTONMATRIX_CTRL_CHECKABLE,
            };
            lv_buttonmatrix_set_map(obj, map);
            lv_buttonmatrix_set_ctrl_map(obj, ctrl_map);
            lv_buttonmatrix_set_one_checked(obj, true);
            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // list
            lv_obj_t *obj = lv_list_create(parent_obj);
            objects.list = obj;
            lv_obj_set_pos(obj, 13, 209);
            lv_obj_set_size(obj, 180, 263);
        }
        {
            // table
            lv_obj_t *obj = lv_table_create(parent_obj);
            objects.table = obj;
            lv_obj_set_pos(obj, 217, 209);
            lv_obj_set_size(obj, 560, 194);
        }
        {
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            lv_obj_set_pos(obj, 208, 454);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Checkbox");
        }
        {
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 265, 80);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Option 1\nOption 2\nOption 3");
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj3, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 183, 86);
            lv_obj_set_size(obj, 80, 100);
            lv_roller_set_options(obj, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj4, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            lv_obj_set_pos(obj, 207, 415);
            lv_obj_set_size(obj, 50, 25);
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 18, 181);
            lv_obj_set_size(obj, 150, 10);
            lv_slider_set_range(obj, 10, 99);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj5, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 463, 95);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(4278255364));
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj6, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_scale_create(parent_obj);
            lv_obj_set_pos(obj, 328, 434);
            lv_obj_set_size(obj, 240, 40);
            lv_scale_set_mode(obj, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
            lv_scale_set_range(obj, 10, 40);
            lv_scale_set_total_tick_count(obj, 31);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, true);
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            lv_obj_set_pos(obj, 273, 135);
            lv_obj_set_size(obj, 150, 70);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_text(obj, "青岛众瑞");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
        }
        {
            // lv_lottie
            lv_obj_t *obj = lv_lottie_create(parent_obj);
            objects.lv_lottie = obj;
            lv_obj_set_pos(obj, 439, 137);
            lv_obj_set_size(obj, 64, 64);
        }
        {
            // qr_code_parent
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.qr_code_parent = obj;
            lv_obj_set_pos(obj, 580, 30);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 3, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.obj1);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj1;
            lv_arc_set_value(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj3) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 10, 3, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.obj3);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj3;
                lv_dropdown_set_selected(objects.obj3, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        if (!(lv_obj_get_state(objects.obj4) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 11, 3, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.obj4);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj4;
                lv_roller_set_selected(objects.obj4, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 13, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.obj5);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj5;
            lv_slider_set_value(objects.obj5, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 14, 3, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.obj6);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj6;
            lv_led_set_brightness(objects.obj6, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_home() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.home = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lv_input
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.lv_input = obj;
            lv_obj_set_pos(obj, 0, 253);
            lv_obj_set_size(obj, 800, 227);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 10, 18);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_home_obj7, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "<- Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 687, 10);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_home_obj8, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Next-->");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // lv_img_junray
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.lv_img_junray = obj;
            lv_obj_set_pos(obj, 23, 156);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_junray);
        }
        {
            // address
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.address = obj;
            lv_obj_set_pos(obj, 110, 156);
            lv_obj_set_size(obj, 653, 70);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
        }
    }
    lv_keyboard_set_textarea(objects.lv_input, objects.address);
}

void tick_screen_home() {
    void *flowState = getFlowState(0, 1);
}

void create_screen_meter() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.meter = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 277, 76);
            lv_obj_set_size(obj, 220, 220);
            lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);
            lv_scale_set_range(obj, 0, 120);
            lv_scale_set_total_tick_count(obj, 25);
            lv_scale_set_major_tick_every(obj, 4);
            lv_scale_set_label_show(obj, true);
            lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 18, 16);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_meter_obj10, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "<- back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 148, 16);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_meter_obj11, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Animate");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // line_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.line_chart = obj;
            lv_obj_set_pos(obj, 18, 262);
            lv_obj_set_size(obj, 257, 197);
        }
        {
            // line_chart2
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.line_chart2 = obj;
            lv_obj_set_pos(obj, 289, 298);
            lv_obj_set_size(obj, 242, 163);
        }
        {
            // line_chart3
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.line_chart3 = obj;
            lv_obj_set_pos(obj, 552, 211);
            lv_obj_set_size(obj, 224, 248);
        }
        {
            // bar_chart_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.bar_chart_container = obj;
            lv_obj_set_pos(obj, 519, 18);
            lv_obj_set_size(obj, 250, 150);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // chart_wrapper
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.chart_wrapper = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(300), LV_PCT(100));
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // bar_chart
                            lv_obj_t *obj = lv_chart_create(parent_obj);
                            objects.bar_chart = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(80));
                            lv_obj_set_style_flex_grow(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // bar_scale
                            lv_obj_t *obj = lv_scale_create(parent_obj);
                            objects.bar_scale = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), 25);
                            lv_scale_set_mode(obj, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
                            lv_scale_set_range(obj, 1, 12);
                            lv_scale_set_total_tick_count(obj, 12);
                            lv_scale_set_major_tick_every(obj, 1);
                            lv_scale_set_label_show(obj, true);
                            lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            // line_chart4
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.line_chart4 = obj;
            lv_obj_set_pos(obj, 14, 82);
            lv_obj_set_size(obj, 243, 166);
        }
    }
}

void tick_screen_meter() {
    void *flowState = getFlowState(0, 2);
    {
        float timeline_position = getTimelinePosition(flowState);
        
        static struct {
            float last_timeline_position;
            int32_t obj_obj9_y_init_value;
        } anim_state = { -1 };
        
        if (anim_state.last_timeline_position == -1) {
            anim_state.last_timeline_position = 0;
            anim_state.obj_obj9_y_init_value = lv_obj_get_style_prop(objects.obj9, LV_PART_MAIN, LV_STYLE_Y).num;
        }
        
        if (timeline_position != anim_state.last_timeline_position) {
            anim_state.last_timeline_position = timeline_position;
            
            {
                lv_obj_t *obj = objects.obj9;
                
                float y_value = anim_state.obj_obj9_y_init_value;
                
                while (1) {
                    // keyframe #1
                    if (timeline_position < 0) {
                        break;
                    }
                    if (timeline_position >= 0 && timeline_position < 0.5) {
                        float t = (timeline_position - 0) / 0.5;
                        // y
                        {
                            float t2 = eez_easeInQuad(t);
                            y_value = (1 - t2) * y_value + t2 * 40;
                        }
                        break;
                    }
                    y_value = 40;
                    
                    // keyframe #2
                    if (timeline_position >= 0.5 && timeline_position < 1) {
                        float t = (timeline_position - 0.5) / 0.5;
                        // y
                        {
                            float t2 = eez_easeInQuint(t);
                            y_value = (1 - t2) * y_value + t2 * 76;
                        }
                        break;
                    }
                    y_value = 76;
                    
                    break;
                }
                
                lv_style_value_t value;
                
                value.num = (int32_t)roundf(y_value);
                lv_obj_set_local_style_prop(obj, LV_STYLE_Y, value, LV_PART_MAIN);
            }
        }
    }
}



void init_keyboard()
{
    lv_obj_t *ime = lv_ime_pinyin_create(objects.main);
    lv_ime_pinyin_set_dict(ime, lv_100ask_def_pinyin_dict);
    lv_ime_pinyin_set_keyboard(ime, objects.lv_input);
    lv_obj_t *cand_panel = lv_ime_pinyin_get_cand_panel(ime);
    lv_obj_set_size(cand_panel, LV_PCT(100), LV_PCT(10));
    lv_obj_align_to(cand_panel, objects.lv_input, LV_ALIGN_OUT_TOP_MID, 0, 0);
}

void init_chart()
{
    lv_chart_set_type(objects.line_chart, LV_CHART_TYPE_LINE);
    lv_chart_series_t *ser1 = lv_chart_add_series(objects.line_chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t *ser2 = lv_chart_add_series(objects.line_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_SECONDARY_Y);
    int32_t *ser2_y_points = lv_chart_get_y_array(objects.line_chart, ser2);

    uint32_t i;
    for (i = 0; i < 10; i++)
    {
        lv_chart_set_next_value(objects.line_chart, ser1, lv_rand(10, 50));
        ser2_y_points[i] = lv_rand(50, 90);
    }
    lv_chart_refresh(objects.line_chart);
}

void init_bar_chart()
{
    lv_chart_set_type(objects.bar_chart, LV_CHART_TYPE_BAR);
    lv_chart_set_range(objects.bar_chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_range(objects.bar_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 400);
    lv_chart_set_point_count(objects.bar_chart, 12);
    lv_obj_set_style_radius(objects.bar_chart, 0, 0);

    lv_obj_set_style_pad_hor(objects.bar_scale, lv_chart_get_first_point_center_offset(objects.bar_chart), 0);
    static const char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    lv_scale_set_text_src(objects.bar_scale, month);

    lv_chart_series_t *ser1 = lv_chart_add_series(objects.bar_chart, lv_palette_lighten(LV_PALETTE_GREEN, 2), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t *ser2 = lv_chart_add_series(objects.bar_chart, lv_palette_darken(LV_PALETTE_GREEN, 2), LV_CHART_AXIS_PRIMARY_Y);

    uint32_t i;
    for (i = 0; i < 12; i++)
    {
        lv_chart_set_next_value(objects.bar_chart, ser1, lv_rand(10, 60));
        lv_chart_set_next_value(objects.bar_chart, ser2, lv_rand(50, 90));
    }
    lv_chart_refresh(objects.bar_chart);
}

void init_fade_area_line()
{
    lv_chart_set_div_line_count(objects.line_chart2, 5, 7);
    lv_obj_add_event(objects.line_chart2, draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(objects.line_chart2, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
    lv_chart_series_t *ser = lv_chart_add_series(objects.line_chart2, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);

    uint32_t i;
    for (i = 0; i < 10; i++)
    {
        lv_chart_set_next_value(objects.line_chart2, ser, lv_rand(10, 80));
    }
    lv_chart_refresh(objects.line_chart2);
}

static void draw_event_cb(lv_event_t *e)
{
    lv_draw_task_t *task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = lv_draw_task_get_draw_dsc(task);

    if (base_dsc->part == LV_PART_ITEMS && lv_draw_task_get_type(task) == LV_DRAW_TASK_TYPE_LINE)
    {
        add_faded_area(e);
    }

    if (base_dsc->part == LV_PART_MAIN && lv_draw_task_get_type(task) == LV_DRAW_TASK_TYPE_LINE)
    {
        hook_division_lines(e);
    }
}

static void add_faded_area(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_area_t coords;
    lv_obj_get_coords(obj, &coords);

    lv_draw_task_t *task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = lv_draw_task_get_draw_dsc(task);

    const lv_chart_series_t *ser = lv_chart_get_series_next(obj, NULL);
    lv_color_t color = lv_chart_get_series_color(obj, ser);

    lv_draw_line_dsc_t *draw_line_dsc = lv_draw_task_get_draw_dsc(task);
    lv_draw_triangle_dsc_t tri_dsc;

    lv_draw_triangle_dsc_init(&tri_dsc);
    tri_dsc.p[0].x = draw_line_dsc->p1.x;
    tri_dsc.p[0].y = draw_line_dsc->p1.y;
    tri_dsc.p[1].x = draw_line_dsc->p2.x;
    tri_dsc.p[1].y = draw_line_dsc->p2.y;
    tri_dsc.p[2].x = draw_line_dsc->p1.y < draw_line_dsc->p2.y ? draw_line_dsc->p1.x : draw_line_dsc->p2.x;
    tri_dsc.p[2].y = LV_MAX(draw_line_dsc->p1.y, draw_line_dsc->p2.y);
    tri_dsc.bg_grad.dir = LV_GRAD_DIR_VER;

    int32_t full_h = lv_obj_get_height(obj);
    int32_t fract_upper = (int32_t)(LV_MIN(draw_line_dsc->p1.y, draw_line_dsc->p2.y) - coords.y1) * 255 / full_h;
    int32_t fract_lower = (int32_t)(LV_MAX(draw_line_dsc->p1.y, draw_line_dsc->p2.y) - coords.y1) * 255 / full_h;
    tri_dsc.bg_grad.stops[0].color = color;
    tri_dsc.bg_grad.stops[0].opa = 255 - fract_upper;
    tri_dsc.bg_grad.stops[0].frac = 0;
    tri_dsc.bg_grad.stops[1].color = color;
    tri_dsc.bg_grad.stops[1].opa = 255 - fract_lower;
    tri_dsc.bg_grad.stops[1].frac = 255;
    lv_draw_triangle(base_dsc->layer, &tri_dsc);

    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_grad.dir = LV_GRAD_DIR_VER;
    rect_dsc.bg_grad.stops[0].color = color;
    rect_dsc.bg_grad.stops[0].frac = 0;
    rect_dsc.bg_grad.stops[0].opa = 255 - fract_lower;
    rect_dsc.bg_grad.stops[1].color = color;
    rect_dsc.bg_grad.stops[1].frac = 255;
    rect_dsc.bg_grad.stops[1].opa = 0;

    lv_area_t rect_area;
    rect_area.x1 = (int32_t)draw_line_dsc->p1.x;
    rect_area.x2 = (int32_t)draw_line_dsc->p2.x - 1;
    rect_area.y1 = (int32_t)LV_MAX(draw_line_dsc->p1.y, draw_line_dsc->p2.y) - 1;
    rect_area.y2 = (int32_t)coords.y2;
    lv_draw_rect(base_dsc->layer, &rect_dsc, &rect_area);
}

static void hook_division_lines(lv_event_t *e)
{
    lv_draw_task_t *task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = lv_draw_task_get_draw_dsc(task);
    lv_draw_line_dsc_t *line_dsc = lv_draw_task_get_draw_dsc(task);

    if (line_dsc->p1.x == line_dsc->p2.x)
    {
        line_dsc->color = lv_palette_lighten(LV_PALETTE_GREY, 1);
        if (base_dsc->id1 == 3)
        {
            line_dsc->width = 2;
            line_dsc->dash_gap = 0;
            line_dsc->dash_width = 0;
        }
        else
        {
            line_dsc->width = 1;
            line_dsc->dash_gap = 6;
            line_dsc->dash_width = 6;
        }
    }
    else
    {
        if (base_dsc->id1 == 2)
        {
            line_dsc->width = 2;
            line_dsc->dash_gap = 0;
            line_dsc->dash_width = 0;
        }
        else
        {
            line_dsc->width = 2;
            line_dsc->dash_gap = 6;
            line_dsc->dash_width = 6;
        }

        if (base_dsc->id1 == 1 || base_dsc->id1 == 3)
        {
            line_dsc->color = lv_palette_main(LV_PALETTE_GREEN);
        }
        else
        {
            line_dsc->color = lv_palette_lighten(LV_PALETTE_GREY, 1);
        }
    }
}

static void draw_scatter_event_cb(lv_event_t *e)
{
    lv_draw_task_t *draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = lv_draw_task_get_draw_dsc(draw_task);
    if (base_dsc->part == LV_PART_INDICATOR)
    {
        lv_obj_t *obj = lv_event_get_target(e);
        lv_chart_series_t *ser = lv_chart_get_series_next(obj, NULL);
        lv_draw_rect_dsc_t *rect_dsc = lv_draw_task_get_draw_dsc(draw_task);
        uint32_t cnt = lv_chart_get_point_count(obj);

        rect_dsc->bg_opa = (LV_OPA_COVER * base_dsc->id2) / (cnt - 1);

        int32_t *x_array = lv_chart_get_x_array(obj, ser);
        int32_t *y_array = lv_chart_get_y_array(obj, ser);

        uint32_t start_point = lv_chart_get_x_start_point(obj, ser);
        uint32_t p_act = (start_point + base_dsc->id2) % cnt;

        lv_opa_t x_opa = (x_array[p_act] * LV_OPA_50) / 200;
        lv_opa_t y_opa = (y_array[p_act] * LV_OPA_50) / 1000;

        rect_dsc->bg_color = lv_color_mix(lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_BLUE), x_opa + y_opa);
    }
}

static void add_scatter_data(lv_timer_t *timer)
{
    lv_obj_t *chart = lv_timer_get_user_data(timer);
    lv_chart_set_next_value2(chart, lv_chart_get_series_next(chart, NULL), lv_rand(0, 200), lv_rand(0, 1000));
}

void init_scatter_chart()
{
    lv_obj_add_event_cb(objects.line_chart3, draw_scatter_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(objects.line_chart3, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
    lv_obj_set_style_line_width(objects.line_chart3, 0, LV_PART_ITEMS);

    lv_chart_set_type(objects.line_chart3, LV_CHART_TYPE_SCATTER);

    lv_chart_set_range(objects.line_chart3, LV_CHART_AXIS_PRIMARY_X, 0, 200);
    lv_chart_set_range(objects.line_chart3, LV_CHART_AXIS_PRIMARY_Y, 0, 1000);

    lv_chart_set_point_count(objects.line_chart3, 50);

    lv_chart_series_t *ser = lv_chart_add_series(objects.line_chart3, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    uint32_t i;
    for (i = 0; i < 50; i++)
    {
        lv_chart_set_next_value2(objects.line_chart3, ser, lv_rand(0, 200), lv_rand(0, 1000));
    }
    lv_chart_refresh(objects.line_chart3);
    lv_timer_create(add_scatter_data, 100, objects.line_chart3);
}

static void add_circle_data(lv_timer_t *timer)
{
    lv_obj_t *chart = lv_timer_get_user_data(timer);
    lv_chart_series_t *ser = lv_chart_get_series_next(chart, NULL);
    lv_chart_set_next_value(chart, lv_chart_get_series_next(chart, NULL), lv_rand(1, 99));

    uint16_t p = lv_chart_get_point_count(chart);
    uint16_t s = lv_chart_get_x_start_point(chart, ser);
    int32_t *a = lv_chart_get_y_array(chart, ser);

    a[(s + 1) % p] = LV_CHART_POINT_NONE;
    a[(s + 2) % p] = LV_CHART_POINT_NONE;

    lv_chart_refresh(chart);
}

void init_circle_chart()
{
    lv_chart_set_point_count(objects.line_chart4, 40);
    lv_chart_series_t *ser = lv_chart_add_series(objects.line_chart4, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    uint32_t i;
    for (i = 0; i < 40; i++)
    {
        lv_chart_set_next_value(objects.line_chart4, ser, lv_rand(1, 99));
    }
    lv_chart_refresh(objects.line_chart4);
    lv_timer_create(add_circle_data, 300, objects.line_chart4);
}

void init_lottie()
{
    lv_lottie_set_src_data(objects.lv_lottie, lv_example_lottie_approve, lv_example_lottie_approve_size);
#if LV_DRAW_BUF_ALIGN == 4 && LV_DRAW_BUF_STRIDE_ALIGN == 1
    static uint8_t buf[64 * 64 * 4];
    lv_lottie_set_buffer(objects.lv_lottie, 64, 64, buf);
#else
    LV_DRAW_BUF_DEFINE(buf, 64, 64, LV_COLOR_FORMAT_ARGB8888);
    lv_lottie_set_draw_buf(objects.lv_lottie, &buf);
#endif
}

void init_all_chart(){
    init_circle_chart();
    init_bar_chart();
    init_fade_area_line();
    init_chart();
    init_scatter_chart();
}

static void  list_item_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED){
        LV_UNUSED(obj);
        LV_LOG_INFO("CLicked: %s", lv_list_get_button_text(objects.list, obj));
    }
}

void init_list()
{
    lv_obj_t *btn;
    lv_list_add_text(objects.list, "File");
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_FILE, "New");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_DIRECTORY, "Open");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_SAVE, "Save");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_CLOSE, "Delete");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_EDIT, "Edit");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(objects.list, "Connectivity");
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_BLUETOOTH, "Bluetooth");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_GPS, "Gps");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_USB, "Usb");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_BATTERY_FULL, "Battery");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(objects.list, "Exit");
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_OK, "Ok");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
    btn = lv_list_add_btn(objects.list, LV_SYMBOL_CLOSE, "Close");
    lv_obj_add_event_cb(btn, list_item_event_handler, LV_EVENT_CLICKED, NULL);
}

static void table_event_cb(lv_event_t *e)
{
    lv_draw_task_t *draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = lv_draw_task_get_draw_dsc(draw_task);

    if (base_dsc->part == LV_PART_ITEMS)
    {
        uint32_t row = base_dsc->id1;
        uint32_t col = base_dsc->id2;

        if (row == 0)
        {
            lv_draw_label_dsc_t *label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
            if (label_draw_dsc)
            {
                label_draw_dsc->align = LV_TEXT_ALIGN_LEFT;
            }
            lv_draw_fill_dsc_t *fill_dsc = lv_draw_task_get_fill_dsc(draw_task);
            if (fill_dsc)
            {
                fill_dsc->color = lv_color_mix(lv_palette_main(LV_PALETTE_BLUE), fill_dsc->color, LV_OPA_20);
                fill_dsc->opa = LV_OPA_COVER;
            }
        }
        else if (col == 0)
        {
            lv_draw_label_dsc_t *label = lv_draw_task_get_label_dsc(draw_task);
            if (label)
            {
                label->align = LV_ALIGN_CENTER;
            }
            
        }
        
        if (row != 0 && row %2 == 0)
        {
            lv_draw_fill_dsc_t *fill_dsc = lv_draw_task_get_fill_dsc(draw_task);
            if (fill_dsc)
            {
                fill_dsc->color = lv_color_mix(lv_palette_main(LV_PALETTE_GREY), fill_dsc->color, LV_OPA_10);
                fill_dsc->opa = LV_OPA_COVER;
            }
            
        }
    }
}

void init_table()
{
    lv_table_set_cell_value(objects.table, 0, 0, "Name");
    lv_table_set_cell_value(objects.table, 1, 0, "Apple");
    lv_table_set_cell_value(objects.table, 2, 0, "Banana");
    lv_table_set_cell_value(objects.table, 3, 0, "Lemon");
    lv_table_set_cell_value(objects.table, 4, 0, "Grape");
    lv_table_set_cell_value(objects.table, 5, 0, "Melon");
    lv_table_set_cell_value(objects.table, 6, 0, "Peach");
    lv_table_set_cell_value(objects.table, 7, 0, "Nuts");

    lv_table_set_cell_value(objects.table, 0, 1, "Price");
    lv_table_set_cell_value(objects.table, 1, 1, "$7");
    lv_table_set_cell_value(objects.table, 2, 1, "$4");
    lv_table_set_cell_value(objects.table, 3, 1, "$6");
    lv_table_set_cell_value(objects.table, 4, 1, "$2");
    lv_table_set_cell_value(objects.table, 5, 1, "$5");
    lv_table_set_cell_value(objects.table, 6, 1, "$1");
    lv_table_set_cell_value(objects.table, 7, 1, "$9");

    lv_table_set_cell_value(objects.table, 0, 2, "Start");
    lv_table_set_cell_value(objects.table, 1, 2, "7");
    lv_table_set_cell_value(objects.table, 2, 2, "4");
    lv_table_set_cell_value(objects.table, 3, 2, "6");
    lv_table_set_cell_value(objects.table, 4, 2, "2");
    lv_table_set_cell_value(objects.table, 5, 2, "5");
    lv_table_set_cell_value(objects.table, 6, 2, "1");
    lv_table_set_cell_value(objects.table, 7, 2, "9");

    lv_table_set_cell_value(objects.table, 0, 3, "Season");
    lv_table_set_cell_value(objects.table, 1, 3, "7");
    lv_table_set_cell_value(objects.table, 2, 3, "4");
    lv_table_set_cell_value(objects.table, 3, 3, "6");
    lv_table_set_cell_value(objects.table, 4, 3, "2");
    lv_table_set_cell_value(objects.table, 5, 3, "5");
    lv_table_set_cell_value(objects.table, 6, 3, "1");
    lv_table_set_cell_value(objects.table, 7, 3, "9");

    lv_table_set_column_width(objects.table, 0, 560 / 4 - 2);
    lv_table_set_column_width(objects.table, 1, 560 / 4 - 2);
    lv_table_set_column_width(objects.table, 2, 560 / 4 - 2);
    lv_table_set_column_width(objects.table, 3, 560 / 4 - 2);
    lv_obj_add_event_cb(objects.table, table_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(objects.table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
}

void init_qr_code()
{
    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    lv_obj_t *qr = lv_qrcode_create(objects.qr_code_parent);
    lv_obj_set_size(qr, LV_PCT(100), LV_PCT(100));
    lv_qrcode_set_dark_color(qr, fg_color);
    lv_qrcode_set_light_color(qr, bg_color);

    const char *data = "http://junray.com";
    lv_qrcode_update(qr, data, strlen(data));
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, &ui_font_siyuan);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_home();
    create_screen_meter();

    init_keyboard();
    init_all_chart();
    init_list();
    init_table();
    init_lottie();
    init_qr_code();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_home,
    tick_screen_meter,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
