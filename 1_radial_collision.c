/*
 * Object with radius
 *   - Radius should turn green/red depending on if player is in or outside it
 *   - No colliders - use actual math
 *   - Explosion.pgn!!!!!
 */

#include <raylib.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

struct Player {
  Vector2 pos;
  Color colour;
  int h;
  int w;
  float speed;
};

struct Barrel {
  Vector2 pos;
  Color colour;
  int h;
  int w;
  int radius;
};

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "5 big booms");
  SetTargetFPS(120);

  // player structure
  struct Player p;
  p.pos = (Vector2){SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2};
  p.colour = BLACK;
  p.h = 60;
  p.w = 36;
  p.speed = 250.0;

  // barrel structure
  struct Barrel b;
  b.pos = (Vector2){SCREEN_WIDTH - 400, SCREEN_HEIGHT / 2};
  b.colour = RED;
  b.h = 30;
  b.w = 20;
  b.radius = 120;

  while (WindowShouldClose() == false) {
    // update
    if (IsKeyDown(KEY_W))
      p.pos.y -= p.speed * GetFrameTime();
    if (IsKeyDown(KEY_S))
      p.pos.y += p.speed * GetFrameTime();
    if (IsKeyDown(KEY_A))
      p.pos.x -= p.speed * GetFrameTime();
    if (IsKeyDown(KEY_D))
      p.pos.x += p.speed * GetFrameTime();

    // draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(p.pos.x, p.pos.y, p.w, p.h, p.colour);
    DrawRectangle(b.pos.x, b.pos.y, b.w, b.h, b.colour);
    DrawCircleLines(b.pos.x + (b.w / 2), b.pos.y + (b.h / 2), b.radius, b.colour);
    EndDrawing();
  }

  CloseWindow();
}
