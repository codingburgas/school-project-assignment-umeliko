#include "bulgarian.h"
#include "bulgarianTest.h"

void bulgarian()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Texture2D background = LoadTexture("../assets/subjectInfo.png");

    Font customFont = LoadFont("../assets/font.ttf");

    Rectangle testButton = { screenWidth - 1060, screenHeight - 220, 200, 60 };

    bool buttonHover = false;

    const char* infoText1 = "Learn here:";
    const char* infoText2 = "In Bulgarian, nouns are categorized into three genders: masculine, feminine, and neuter.";
    const char* infoText3 = "The Bulgarian Cyrillic alphabet consists of 30 letters.";
    const char* infoText4 = "In Bulgarian, the definite article is a suffix that is added to the end of the noun.";
    const char* infoText5 = "Bulgarian is indeed a Slavic language, but it uses the Cyrillic alphabet, not the Latin alphabet.";
    const char* infoText6 = "Verbs in Bulgarian have two aspects: perfective and imperfective.";
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

        DrawTextEx(customFont, "Bulgarian", Vector2{ 800, 50 }, 59, 2, WHITE);
        DrawTextEx(customFont, infoText1, Vector2{ 100, 280 }, 45, 2, DARKGREEN);  // Ot 45 se promenq razmera na teksta
        DrawTextEx(customFont, infoText2, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText3, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText4, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText5, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText6, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawRectangleRec(testButton, buttonHover ? BLACK: BLACK);

        DrawTextEx(customFont, "Take a test", Vector2{ testButton.x + 10, testButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bulgarianTest();
        }
    }

    UnloadTexture(background);
    CloseWindow();
}

