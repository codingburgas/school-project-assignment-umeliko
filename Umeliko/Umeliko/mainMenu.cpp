
#include "mainMenu.h"

void menu()
{
    // Initialization
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Umeliko");

    // Load textures
    Texture2D background = LoadTexture("../assets/background.png");
    Font customFont = LoadFont("../assets/font.ttf");
    // Define the button
    Rectangle startButton = { screenWidth / 2.0f - 115, screenHeight - 275, 300, 90 };
    bool buttonHover = false;

    // Set up the motivational text
    const char* motivationalText = "Unlock your potential. Every journey begins with a single step.";
    const char* motivationalText2 = "Start yours today!";
    Vector2 mtPosition = { screenWidth * 0.25f, screenHeight * 0.4f };

    SetTargetFPS(60); // Set the desired frames per second

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        Vector2 mousePoint = GetMousePosition();
        buttonHover = CheckCollisionPointRec(mousePoint, startButton);

        // Start the drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw the background
        DrawTexture(background, 0, 0, WHITE);

        // Draw the motivational text
        DrawTextEx(customFont, motivationalText, Vector2{ 100, 280 }, 45, 2, DARKGREEN);
        DrawTextEx(customFont, motivationalText2, Vector2{ 100, 380 }, 60, 2, WHITE);

        // Draw the "Umeliko" text
        DrawTextEx(customFont, "Umeliko", Vector2{ 850, 50 }, 70, 2, WHITE);

        // Draw the button
        DrawRectangleRec(startButton, buttonHover ? DARKGRAY : DARKGRAY);

        Vector2 buttonTextSize = MeasureTextEx(customFont, "Start Learning!", 40, 2);
        DrawTextEx(customFont, "Start Learning!", Vector2{ startButton.x + (startButton.width - buttonTextSize.x) / 2, startButton.y + (startButton.height - buttonTextSize.y) / 2 }, 40, 2, WHITE);

        if (buttonHover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Button clicked, proceed to the next screen or activity
        }

        EndDrawing();
    }

    // De-Initialization
    UnloadFont(customFont);
    UnloadTexture(background); // Unload textures
    CloseWindow(); // Close window and OpenGL context

    return 0;
}