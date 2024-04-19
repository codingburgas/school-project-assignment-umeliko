#include <iostream>
#include <string>
#include "raylib.h"

using namespace std;

int main() {

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Umeliko");


    Texture2D background = LoadTexture("../assets/background.png");
    Font customFont = LoadFont("../assets/font.ttf");

    Rectangle startButton = { screenWidth / 2.0f - 115, screenHeight - 275, 300, 90 };
    bool buttonHover = false;

    const char* motivationalText = "Unlock your potential. Every journey begins with a single step.";
    const char* motivationalText2 = "Start yours today!";
    Vector2 mtPosition = { screenWidth * 0.25f, screenHeight * 0.4f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();
        buttonHover = CheckCollisionPointRec(mousePoint, startButton);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTextEx(customFont, motivationalText, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, motivationalText2, Vector2{ 100, 380 }, 60, 2, WHITE);

        DrawTextEx(customFont, "Umeliko", Vector2{ 850, 50 }, 70, 2, WHITE);

        DrawRectangleRec(startButton, buttonHover ? DARKGRAY : DARKGRAY);

        Vector2 buttonTextSize = MeasureTextEx(customFont, "Start Learning!", 40, 2);
        DrawTextEx(customFont, "Start Learning!", Vector2{ startButton.x + (startButton.width - buttonTextSize.x) / 2, startButton.y + (startButton.height - buttonTextSize.y) / 2 }, 40, 2, WHITE);

        if (buttonHover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Texture2D background = LoadTexture("../assets/info.png");
        }
        EndDrawing();
    }

    UnloadFont(customFont);
    UnloadTexture(background); 
    CloseWindow();

    return 0;
}