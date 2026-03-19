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





