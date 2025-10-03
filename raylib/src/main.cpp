#include "raylib.h"
#include "imgui.h"

int main() {
  InitWindow(800, 600, "Raylib + fmt test");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();

  return 0;
}
