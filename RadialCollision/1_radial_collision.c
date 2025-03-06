#include <raylib.h>
#include <math.h>

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
  bool playerNear;
};

// Calculates distance between two vectors
// Subtract the second Vectors axis' with the first to get Distance
// return square root cause pythagoraease said so
float Distance(Vector2 Player, Vector2 Barrel) {
    float dx = Barrel.x - Player.x;
    float dy = Barrel.y - Player.y;

    return sqrt(dx * dx + dy * dy);
}

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
  b.colour = GREEN;
  b.h = 30;
  b.w = 20;
  b.radius = 120;
  b.playerNear = false;

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

    // get the distance between player and barrel
    float dist = Distance(p.pos, b.pos);

    // if distance is less than or equal to the barrel's radius
    if (dist <= b.radius) {
      b.colour = RED;
    } else {
      b.colour = GREEN;
      // imagine there's a really cool and highly detailed explosion animation here
    }

    DrawCircleLines(b.pos.x + (b.w / 2), b.pos.y + (b.h / 2), b.radius, b.colour);
    DrawRectangle(b.pos.x, b.pos.y, b.w, b.h, b.colour);

    EndDrawing();
  }

  CloseWindow();
}
