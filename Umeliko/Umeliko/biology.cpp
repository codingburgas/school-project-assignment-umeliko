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
    const char* infoText2 = "During photosynthesis, plants use carbon dioxide and water to produce glucose and oxygen.";
    const char* infoText3 = "Mitochondria are organelles that generate energy for the cell through cellular respiration.";
    const char* infoText4 = "Viruses are not made up of cells; they are made up of genetic material (DNA or RNA) surrounded by a protein coat.";
    const char* infoText5 = "An adult human typically has 206 bones.";
    const char* infoText6 = "Hibernation is a survival strategy adopted by some animals to conserve energy during periods of food scarcity.";



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