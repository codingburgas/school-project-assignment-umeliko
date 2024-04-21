#include "biology.h"

void biology()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Texture2D background = LoadTexture("../assets/subjectInfo.png");

    Font customFont = LoadFont("../assets/font.ttf");

    Rectangle testButton = { screenWidth - 1100, screenHeight - 270, 180, 50 };

    bool buttonHover = false;

    const char* infoText1 = "Learn here:";
    


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
        DrawTextEx(customFont, infoText1, Vector2{ 100, 280 }, 45, 2, DARKGREEN);  // Ot chisloto 45 se promenq razmera na teksta. Ako iskash da go napraish po maluk namalqsh nego

        DrawRectangleRec(testButton, buttonHover ? DARKGRAY : DARKGRAY);

        DrawTextEx(customFont, "Take a test", Vector2{ testButton.x + 10, testButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // test
        }
    }

    UnloadTexture(background);
    CloseWindow();
}