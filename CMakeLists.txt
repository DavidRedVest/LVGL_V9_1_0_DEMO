cmake_minimum_required(VERSION 3.10)
project(LVGL_Mac_Simulator C)

# 指定 C 语言标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. 定义你的 SDL2 本地路径
set(SDL2_DIR "$ENV{HOME}/home/ffmpeg_dynamic_build/common_libs")

# 2. 引入 LVGL 官方自带的 CMake 配置
# 这句话会自动解析 lvgl 目录下的 CMakeLists.txt，提取所有需要编译的核心文件
add_subdirectory(lvgl)

# 【关键扩充】
# 把当前根目录（找 lv_conf.h）和 自定义 SDL2 目录（找 SDL.h）
# 统统赋给 lvgl 库，并且设为 PUBLIC！
target_include_directories(lvgl PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SDL2_DIR}/include
    ${SDL2_DIR}/include/SDL2
)

# 3. 收集你自己的源码（主程序和 demos）
file(GLOB_RECURSE OFFICIAL_DEMOS "lvgl/demos/*.c")
file(GLOB_RECURSE MY_DEMOS "demos/*.c")
add_executable(run_lvgl main.c ${OFFICIAL_DEMOS} ${MY_DEMOS})

# 4. 指定头文件搜索路径 (等同于 Makefile 的 -I)

# 5. 指定库文件搜索路径和链接库 (等同于 Makefile 的 -L 和 -l)
target_link_directories(run_lvgl PRIVATE ${SDL2_DIR}/lib)
target_link_libraries(run_lvgl PRIVATE lvgl SDL2)

# 6. 极其关键：设置 RPATH，解决 Mac 下动态库运行时加载失败的问题
set_target_properties(run_lvgl PROPERTIES INSTALL_RPATH "${SDL2_DIR}/lib")
# 针对 Mac 环境开启一些特定宏
if(APPLE)
    target_compile_definitions(run_lvgl PRIVATE __APPLE__)
endif()
