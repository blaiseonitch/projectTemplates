#include <raylib.h>

int main() {
  InitWindow(800, 500, "raylib");
  SetExitKey(KEY_NULL);
  SetTargetFPS(30);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
