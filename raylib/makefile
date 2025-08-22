# === Config ===
CC_LINUX = gcc
CC_WINDOWS = x86_64-w64-mingw32-gcc

VCPKG_ROOT = /home/blaze/vcpkg

SRC = src/main.c
TARGET_DIR = build
TARGET_LINUX = $(TARGET_DIR)/main_linux
TARGET_WINDOWS = $(TARGET_DIR)/main_windows.exe

# === Flags for Linux ===
CFLAGS_LINUX = -std=c11 -Isrc/include -I$(VCPKG_ROOT)/installed/x64-linux/include
LDFLAGS_LINUX = -L$(VCPKG_ROOT)/installed/x64-linux/lib \
	-lraylib -lopus -lvorbis -lvorbisfile -lglfw3 -lm -ldl -lpthread -lGL -lX11

# === Flags for Windows (cross-compile) ===
CFLAGS_WINDOWS = -std=c11 -Isrc/include -I$(VCPKG_ROOT)/installed/x64-mingw-static/include
LDFLAGS_WINDOWS = -L$(VCPKG_ROOT)/installed/x64-mingw-static/lib \
	-lraylib  -lvorbis -lvorbisfile -lglfw3 -lwinmm -lgdi32 -lopengl32 -lkernel32 -luser32

# === Debug flags ===
DEBUG_FLAGS = -g -DDEBUG

# === Rules ===
.PHONY: all linux windows run_linux run_windows debug debug-linux debug-windows clean

# === Default build (Linux) ===
all: linux windows

linux: $(TARGET_LINUX)

windows: $(TARGET_WINDOWS)

# === Run executables ===
run_linux: $(TARGET_LINUX)
	./$(TARGET_LINUX)

run_windows: $(TARGET_WINDOWS)
	./$(TARGET_WINDOWS)

# === Debug builds ===
debug: debug-linux

debug-linux: CFLAGS_LINUX += $(DEBUG_FLAGS)
debug-linux: $(TARGET_LINUX)

debug-windows: CFLAGS_WINDOWS += $(DEBUG_FLAGS)
debug-windows: $(TARGET_WINDOWS)

# === Build commands ===
$(TARGET_LINUX): $(SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC_LINUX) $(CFLAGS_LINUX) $^ $(LDFLAGS_LINUX) -o $@

$(TARGET_WINDOWS): $(SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC_WINDOWS) $(CFLAGS_WINDOWS) $^ $(LDFLAGS_WINDOWS) -o $@

# === Clean up ===
clean:
	rm -rf $(TARGET_DIR)
