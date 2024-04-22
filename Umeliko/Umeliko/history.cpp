#include "history.h"
#include "historyTest.h"
void history()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Texture2D background = LoadTexture("../assets/subjectInfo.png");

    Font customFont = LoadFont("../assets/font.ttf");

    Rectangle testButton = { screenWidth - 1060, screenHeight - 220, 200, 60 };

    bool buttonHover = false;

    const char* infoText1 = "Learn here:";
    const char* infoText2 = "Political Ideologies: ";
    const char* infoText3 = "   We'll cover socialism,conservatism,authoritarianism,and liberalism,";
    const char* infoText4 = "  with liberalism being a hallmark of the modern era.";
    const char* infoText5 = "Ottoman Empire Reforms:"; 
    const char* infoText6 = "   From 1839 to 1876, the Ottoman Empire underwent reforms";
    const char* infoText7 = "  known as the Tanzimat era, modernizing its systems.";
    const char* infoText8 = "American Constitution: ";
    const char* infoText9 = "   Ratified in 1789, it established federalism and the separation of powers."; 
    const char* infoText10 = "Bulgarian Revival: ";
    const char* infoText11 = "  The cultural awakening in the early 19th century."; 
    const char* infoText12 = "Giuseppe Garibaldi: A key figure in Italy's unification during the 19th century.";

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

        DrawTextEx(customFont, "History", Vector2{ 810, 50 }, 59, 2, WHITE);
        DrawTextEx(customFont, infoText1, Vector2{ 100, 190 }, 30, 2, DARKGREEN); 
        DrawTextEx(customFont, infoText2, Vector2{ 100, 250 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText3, Vector2{ 100, 300 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText4, Vector2{ 100, 350 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText5, Vector2{ 100, 400 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText6, Vector2{ 100, 450 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText7, Vector2{ 100, 500 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText8, Vector2{ 100, 550 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText9, Vector2{ 100, 600 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText10, Vector2{ 100, 650 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText11, Vector2{ 100, 700 }, 30, 2, DARKGREEN);
        DrawTextEx(customFont, infoText12, Vector2{ 100, 750 }, 30, 2, DARKGREEN);

        DrawRectangleRec(testButton, buttonHover ? BLACK : BLACK);

        DrawTextEx(customFont, "Take a test", Vector2{ testButton.x + 10, testButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            historyTest();
        }
    }

    UnloadTexture(background);
    CloseWindow();
}