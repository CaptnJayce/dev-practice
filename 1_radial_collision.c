/*
* Object with radius
*   - Radius should turn green/red depending on if player is in or outside it
*   - Explosion.pgn!!!!!
*/  

#include <raylib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 360

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first RAYLIB program!");
  SetTargetFPS(60);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
}
