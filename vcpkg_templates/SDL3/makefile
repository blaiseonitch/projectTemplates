# === Config ===
CC_LINUX = gcc
CC_WINDOWS = x86_64-w64-mingw32-gcc

VCPKG_ROOT = /home/blaze/vcpkg

SRC = main.c
TARGET_DIR = build
TARGET_LINUX = $(TARGET_DIR)/main_linux
TARGET_WINDOWS = $(TARGET_DIR)/main_windows.exe

# === Flags for Linux ===
CFLAGS_LINUX = -std=c11 -DSDL_MAIN_USE_CALLBACKS=1 -Isrc/include -I$(VCPKG_ROOT)/installed/x64-linux/include
LDFLAGS_LINUX = -L$(VCPKG_ROOT)/installed/x64-linux/lib \
	-lSDL3 -lm -ldl -lpthread -lGL -lX11

# === Flags for Windows (cross-compile) ===
CFLAGS_WINDOWS = -std=c11 -DSDL_MAIN_USE_CALLBACKS=1 -Isrc/include -I$(VCPKG_ROOT)/installed/x64-mingw-static/include
LDFLAGS_WINDOWS = -L$(VCPKG_ROOT)/installed/x64-mingw-static/lib \
	-lSDL3 -lwinmm -lgdi32 -lopengl32 -lkernel32 -luser32 \
	-lole32 -luuid -lcomdlg32 -lshell32 -limm32 -lversion -lsetupapi -loleaut32

# === Rules ===
.PHONY: all linux windows run run-windows clean

all: linux

linux: $(TARGET_LINUX)

windows: $(TARGET_WINDOWS)

run: $(TARGET_LINUX)
	./$<

run-windows: $(TARGET_WINDOWS)
	WINEDEBUG=-all wine $<

$(TARGET_LINUX): $(SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC_LINUX) $(CFLAGS_LINUX) $^ $(LDFLAGS_LINUX) -o $@

$(TARGET_WINDOWS): $(SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC_WINDOWS) $(CFLAGS_WINDOWS) $^ $(LDFLAGS_WINDOWS) -o $@

clean:
	rm -rf $(TARGET_DIR)
