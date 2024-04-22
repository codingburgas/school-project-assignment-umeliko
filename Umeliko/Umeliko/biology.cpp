#include "biology.h"
#include "biologyTest.h"


void biology()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Texture2D background = LoadTexture("../assets/subjectInfo.png");

    Font customFont = LoadFont("../assets/font.ttf");

    Rectangle testButton = { screenWidth - 1060, screenHeight - 220, 200, 60 };

    bool buttonHover = false;

    const char* infoText1 = "Learn here:";
    const char* infoText2 = "";
    const char* infoText3 = "";
    const char* infoText4 = "";
    const char* infoText5 = "";
    const char* infoText6 = "";



    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition();
        bool isMouseOverButton = CheckCollisionPointRec(mousePosition, testButton);
        buttonHover = CheckCollisionPointRec(mousePosition, testButton);
        if (CheckCollisionPointRec(mousePosition, testButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            buttonHover = true;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTextEx(customFont, "Biology", Vector2{ 800, 50 }, 59, 2, WHITE);
        DrawTextEx(customFont, infoText1, Vector2{ 100, 280 }, 45, 2, DARKGREEN);  
        DrawTextEx(customFont, infoText2, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText3, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText4, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText5, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText6, Vector2{ 100, 280 }, 45, 2, DARKGREEN);

        DrawRectangleRec(testButton, buttonHover ? BLACK : BLACK);

        DrawTextEx(customFont, "Take a test", Vector2{ testButton.x + 10, testButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            biologyTest();
        }
    }

    UnloadTexture(background);
    CloseWindow();
}