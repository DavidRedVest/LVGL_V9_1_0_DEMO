# 使用 macOS 默认的高性能 clang 编译器
CC = clang
  
SDL2_DIR = /Users/liszt/home/ffmpeg_dynamic_build/common_libs

# 编译优化与头文件路径 (请根据你 mac_sdl2 里的实际结构调整 SDL 的路径)
CFLAGS = -O3 -I. -I./lvgl -I$(SDL2_DIR)/include 
CFLAGS += -I./modules

# 链接器参数 (指定 SDL2 动态库的位置)
LDFLAGS = -L$(SDL2_DIR)/lib -lSDL2
LDFLAGS += -Wl,-rpath,$(SDL2_DIR)/lib

# 收集所有需要编译的 C 文件
CSRCS += main.c
CSRCS += $(shell find lvgl/src -name \*.c)
# 未来如果有自己写的 demos，取消下面这行的注释即可
# CSRCS += $(shell find demos -name \*.c)
CSRCS += $(shell find lvgl/demos -name \*.c)
CSRCS += $(shell find modules/src -name \*.c)

# 将 .c 文件转换为对应的 .o 目标文件
OBJS = $(CSRCS:.c=.o)

# 最终生成的可执行文件名称
TARGET = run_lvgl

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)