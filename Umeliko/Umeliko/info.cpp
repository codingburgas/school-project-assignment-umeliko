#include "info.h"
#include "subjects.h"

void info()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

	Texture2D background = LoadTexture("../assets/info.png");

	Font customFont = LoadFont("../assets/font.ttf");

    Rectangle proceedButton = { screenWidth - 260, screenHeight - 225, 190, 60 };

    bool buttonHover = false;

    const char* infoText1 = "Welcome to our team's application. "; 
    const char* infoText2 = "We have made it to help students learn and test their kowledge";
    const char* infoText3 = "on a subject they select. When you click on the button Proceed,";
    const char* infoText4 = "you go to the page you choose your subject from."; 
    const char* infoText5 = "There are Bulgarian language, Geography, History and Biology.";
  

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
        DrawTextEx(customFont, infoText1, Vector2{ 100, 280 }, 45, 2, DARKGREEN);  
        DrawTextEx(customFont, infoText2, Vector2{ 100, 330 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText3, Vector2{ 100, 380 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, infoText4, Vector2{ 100, 430 }, 45, 2, DARKGREEN); 
        DrawTextEx(customFont, infoText5, Vector2{ 100, 480 }, 45, 2, DARKGREEN);
        DrawRectangleRec(proceedButton, buttonHover ? BLACK : BLACK);

        DrawTextEx(customFont, "PROCEED", Vector2{ proceedButton.x + 10, proceedButton.y + 10 }, 33, 2, WHITE);

        EndDrawing();

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            subjects();
        }
    }

    UnloadTexture(background);
    CloseWindow();
}