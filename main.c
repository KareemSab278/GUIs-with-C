#include "raylib.h"

// im gonna try making a few balls float around and bounch with some physics for fun soon...
// https://github.com/wisonye/raylib-box2d-tutorials/blob/master/tutorials/c-a-how-to-draw-basic-shapes.org

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    int screenWidth = 800, screenHeight = 500;
    InitWindow(screenWidth, screenHeight, "Fix Zoom");
    SetWindowSize(screenWidth, screenHeight);
    SetTargetFPS(60);

    int currentGesture = GESTURE_NONE;
    Vector2 touchPosition = { 0, 0 };
    
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };


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
       
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

        if (currentGesture == GESTURE_DRAG){

            DrawCircleV(touchPosition, 30, MAROON);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
