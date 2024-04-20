#include "info.h"

void info()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

	Texture2D background = LoadTexture("../assets/info.png");

	Font customFont = LoadFont("../assets/font.ttf");

    Rectangle proceedButton = { screenWidth - 260, screenHeight - 200, 180, 50 };

    bool buttonHover = false;

    const char* infoText = "asdfhsdrthsrfth"; // Ei tuka trqq da napishesh teksta tam za informaciq za nas

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition();
        bool isMouseOverButton = CheckCollisionPointRec(mousePosition, proceedButton);
        buttonHover = CheckCollisionPointRec(mousePosition, proceedButton);
        if (CheckCollisionPointRec(mousePosition, proceedButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            buttonHover = true;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawTextEx(customFont, "About the app", Vector2{ 800, 50 }, 59, 2, WHITE);
        DrawTextEx(customFont, infoText, Vector2{ 100, 280 }, 45, 2, DARKGREEN);  // Ei tuka samiq tekst se risuva. Kato promenqsh cifrichkite, mqstoto na teksta se promenq. Cifrata 2 e za razstoqnieto mejdu bukvite, neq ne q barai.

        DrawRectangleRec(proceedButton, buttonHover ? DARKGRAY : DARKGRAY);

        DrawTextEx(customFont, "PROCEED", Vector2{ proceedButton.x + 10, proceedButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // subjects
        }
    }

    UnloadTexture(background);
    CloseWindow();
}