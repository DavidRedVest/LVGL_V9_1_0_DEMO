# 说明 

- 在win11上使用codeblocks编译通过，可以正常运行LVGL的Demo程序

- 现在改进使用SDL2，完成在Macbook m4 pro笔记本上环境搭建；增加Makefile文件，并且修改Windows和Mac的宏定义开关，完成了Macbook M4 Pro电脑上环境搭建。使用方法：

  ```C
  make clean
  make -j10
  ./run_lvgl
  ```

- 新增加 Makefile 用于macOS 环境下Clang多线程编译

- 修改lv_conf.h及main.c，利用宏定义隔离windows GDI 与 macOS SDL2底层

- 引入SDL2动态库并在LDFLAGS中配置RPATH解决运行时加载问题

- 增加.gitignore文件，不上传.o文件和最终的可执行文件

- 完善 c_cpp_properties.json 配置，解决代码补全提示

- 修复 lv_conf.h下LV_USE_SDL重复定义的问题，同时测试了win11下运行正常

- 移除原有的 Makefile，新增 CMakeLists.txt 作为全局构建脚本

- 配置 SDL2 动态库的绝对搜索路径，并利用 RPATH 解决 macOS 运行时加载问题

- 调整 target_include_directories 作用域为 PUBLIC，解决 LVGL 内部找不到 lv_conf.h 的问题

- 将官方 lvgl/demos 源码加入编译树，修复 _lv_demo_widgets 链接失败问题

- 统一 Mac 模拟器与未来 MCU 裸机工程的构建逻辑抽象

- CMake使用方法：

  ```C
  //进入CMake编译目录
  cd build/
  //重新解析CMakeLists.txt并生成构建树
  cmake ..
  //再次启动多线程编译
  cmake --build . -j10
  //运行可执行程序
  ./run_lvgl
  ```

  





