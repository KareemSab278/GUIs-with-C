#include "raylib.h"

// im gonna try making a few balls float around and bounch with some physics for fun soon...

int main(void)
{
    InitWindow(800, 500, "Fix Zoom");
    SetWindowSize(800, 500);
    SetTargetFPS(60);
    Rectangle button = {350, 100, 100, 50}; // x, y, width, height

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }

        DrawRectangleRec(button, LIGHTGRAY);
        DrawText("button", button.x + 10, button.y + 15, 20, BLACK);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
            CheckCollisionPointRec(GetMousePosition(), button))
        {
            DrawText("Button Clicked!", 300, 300, 20, RED);
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("My first GUI in C!", 300, 200, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
