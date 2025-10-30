#include "raylib.h"
#include <stdio.h>

// im gonna try making a few balls float around and bounch with some physics for fun soon...
// https://github.com/wisonye/raylib-box2d-tutorials/blob/master/tutorials/c-a-how-to-draw-basic-shapes.org

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib Ball Demo");
    SetWindowSize(screenWidth, screenHeight);
    SetTargetFPS(75);

    int currentGesture = GESTURE_NONE;
    Vector2 touchPosition = {0, 0};

    Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2}; // middle of screen

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }
        // =========================================================
        // MAIN RENDER
        // =========================================================
        BeginDrawing();            // anything below this is rendered, before it is ignored
        ClearBackground(DARKBLUE); // this must be directly below beginDrawing

        DrawCircleV(ballPosition, 50, GREEN); // position height, position width, size, and color
        float moveSpeed = 2.0f;
        if (IsKeyDown(KEY_LEFT_SHIFT))
            moveSpeed = 4.0f;
        if (IsKeyDown(KEY_D))
            ballPosition.x += moveSpeed;
        if (IsKeyDown(KEY_A))
            ballPosition.x -= moveSpeed;
        if (IsKeyDown(KEY_W))
            ballPosition.y -= moveSpeed;
        if (IsKeyDown(KEY_S))
            ballPosition.y += moveSpeed;

        if (currentGesture == GESTURE_DRAG)
        {
            DrawCircleV(touchPosition, 30, MAROON);
        }

        char ballPositionText[100];

        screenHeight = GetScreenHeight();
        screenWidth = GetScreenWidth();

        // keep ball in window bounds
        if (ballPosition.x > screenWidth)
            ballPosition.x = screenWidth;
        if (ballPosition.y > screenHeight)
            ballPosition.y = screenHeight;
        if (ballPosition.x < 0)
            ballPosition.x = 0;
        if (ballPosition.y < 0)
            ballPosition.y = 0;
        sprintf(ballPositionText, "BALL POSITION: %d, %d", (int)ballPosition.x, (int)ballPosition.y);
        DrawText(ballPositionText, 10, 10, 10, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
