#include "geography.h"
#include "geographyTest.h"

void geography()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Texture2D background = LoadTexture("../assets/subjectInfo.png");

    Font customFont = LoadFont("../assets/font.ttf");

    Rectangle testButton = { screenWidth - 1060, screenHeight - 220, 200, 60 };

    bool buttonHover = false;

    const char* infoText1 = "Learn here:";
    const char* infoText2 = "The capital of France is Paris."; 
    const char* infoText3 = "Mount Everest, located in the Himalayas, is the tallest mountain above sea level.";
    const char* infoText4 = "The Sahara Desert in Africa is the largest hot desert globally.";
    const char* infoText5 = "The Nile River in Africa is the longest river in the world.";
    const char* infoText6 = "Australia is the smallest continent and also the name of the country.";
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

        DrawTextEx(customFont, "Geography", Vector2{ 800, 50 }, 59, 2, WHITE);
        DrawTextEx(customFont, infoText1, Vector2{ 100, 280 }, 30, 2, DARKGREEN);  
        DrawTextEx(customFont, infoText2, Vector2{ 100, 320 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText3, Vector2{ 100, 360 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText4, Vector2{ 100, 400 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText5, Vector2{ 100, 440 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText6, Vector2{ 100, 480 }, 30, 2, DARKGREEN);
        DrawRectangleRec(testButton, buttonHover ? BLACK : BLACK);

        DrawTextEx(customFont, "Take a test", Vector2{ testButton.x + 10, testButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            geographyTest();
        }
    }

    UnloadTexture(background);
    CloseWindow();
}