#include "subjects.h"
#include "bulgarian.h"
#include "history.h"
#include "geography.h"
#include "biology.h"

void subjects()
{
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	Texture2D background = LoadTexture("../assets/subjects.png");

	Font customFont = LoadFont("../assets/font.ttf");
    Button buttons[4];
    buttons[0] = { { 460, 280, 200, 100 }, "Bulgarian" };
    buttons[1] = { { 1115, 280, 200, 100 }, "History" };
    buttons[2] = { { 460, 620, 200, 100 }, "Geography" };
    buttons[3] = { { 1125, 620, 200, 100 }, "Biology" };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, screenWidth / 2 - background.width / 2, screenHeight / 2 - background.height / 2, WHITE);

        for (Button button : buttons) {
            bool isHover = CheckCollisionPointRec(GetMousePosition(), button.rect);
            DrawRectangleRec(button.rect, isHover ? BLACK : BLACK);
            DrawTextEx(customFont, button.label, Vector2{ button.rect.x + (button.rect.width / 2 - MeasureText(button.label, 20) / 2), button.rect.y + (button.rect.height / 2 - 10) }, 40, 2, WHITE);
        }
        if (CheckCollisionPointRec(GetMousePosition(), buttons[0].rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            bulgarian();
        }
        if (CheckCollisionPointRec(GetMousePosition(), buttons[1].rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            history();
        }
        if (CheckCollisionPointRec(GetMousePosition(), buttons[2].rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            geography();
        }
        if (CheckCollisionPointRec(GetMousePosition(), buttons[3].rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            biology();
        }

        EndDrawing();
    }

    UnloadTexture(background);

    CloseWindow();

}