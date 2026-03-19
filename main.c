#include <stdlib.h>
#include <unistd.h>


#include "../lv_conf.h"
#include "../lvgl/lvgl.h"
#include "../lvgl/demos/lv_demos.h"
#include "../lvgl/examples/lv_examples.h"
#include "../lvgl/demos/widgets/lv_demo_widgets.h"

#include "../modules/lv_modules.h"

/* 根据平台包含不同的系统头文件 */
#if defined(_WIN32)
    #include <windows.h>
#elif defined(__APPLE__)
    #include <unistd.h>
    /* 注意：根据SDL具体目录，有可能是 “SDL.h”或者<SDL2/SDL.h> */
    #inlcude "SDL2/SDL.h"
#endif

static const wchar_t * title = L"百问网LVGL课程案例  © Copyright 2024, Shenzhen Baiwenwang Technology Co., Ltd.   https://www.100ask.net | https://lvgl.100ask.net";

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow)
{
/*Initialize LVGL*/
    lv_init();

    /* 根据平台初始化不同的显示和输入后端 */
#if defined(_WIN32)    
    /*Initialize the HAL for LVGL*/
    lv_display_t * display = lv_windows_create_display(title, 1024, 600, 100, FALSE, FALSE);
    lv_windows_acquire_pointer_indev(display);
#elif defined(__APPLE__)
    /* LVGL v9 的SDL初始化方式 */
    lv_display_t *display = lv_sdl_window_create(title, 1024, 600);
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();
#endif
    /*Output prompt information to the console, you can also use printf() to print directly*/
    LV_LOG_USER("LVGL initialization completed!");

    lv_demo_widgets();

    //lesson_2_3_1();         // 基础对象(lv_obj)，"Hello, LVGL


    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(5000);       /*Just to let the system breath*/
    }
    return 0;

    return 0;
}
