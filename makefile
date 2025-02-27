# 編譯器
CC = clang

# 編譯選項
CCFLAGS = -Wall -Wextra
LDFLAGS = -lSDL2 -lSDL2main -lm

PLATFORM = SDL

# 預設平台定義
ifeq ($(PLATFORM), SDL)
$(info Compiling for SDL...)
DEFINE_PLATFORM = -D_3DR_PLATFORM_SDL
PLATFORM_IMPLEMENT = platform/sdl_implement.c
endif

OBJS = main.o \
platform.o \
lib/graphical/transform.o \
lib/graphical/triangle_rasterization.o \
lib/frame_buffer/frame_buffer.o \
lib/utils/vector.o \
lib/utils/matrix.o \
lib/model/obj_parser.o

# 目標可執行檔
output.out: $(OBJS)
	$(CC) $(CCFLAGS) $(DEFINE_PLATFORM) $(OBJS) -o output.out $(LDFLAGS)

# 平台相關編譯規則
platform.o: 
	$(CC) $(CCFLAGS) -c $(PLATFORM_IMPLEMENT) -o platform.o

# 泛用規則（適用於所有 .c 檔案）
%.o: %.c
	$(CC) $(CCFLAGS) $(DEFINE_PLATFORM) -c $< -o $@

# 清除目標檔案
clean:
	rm -rf *.o */*.o */*/*.o
	rm -rf *.tmp */*.tmp */*/*.tmp
	rm -f output.out

run: output.out
	./output.out