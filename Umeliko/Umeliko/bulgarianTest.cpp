#include "bulgarianTest.h"
#include <raylib.h>
#include <vector>
#include <string>
#include <algorithm> 
#include <ctime>

using namespace std;

struct Question {
    string text;
    string option1;
    string option2;
    int correctOption;
};

void bulgarianTest()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Umeliko");

    Texture2D background = LoadTexture("../assets/subjectInfo.png");
    Font customFont = LoadFont("../assets/font.ttf");

    SetTargetFPS(60);


    vector<Question> questions = {
        {"In Bulgarian, nouns are categorized into three genders: masculine, feminine, and neuter.", "True", "False", 1}, 
        {"The Bulgarian Cyrillic alphabet consists of 30 letters", "True", "False", 2}, 
        {"In Bulgarian, the definite article is a suffix that is added to the end of the noun.", "True", "False", 1},
        {"Bulgarian is indeed a Slavic language, but it uses the Cyrillic alphabet, not the Latin alphabet.", "True", "False", 2},
        {"Verbs in Bulgarian have two aspects: perfective and imperfective.", "True", "False", 1},
        {"In Bulgarian, nouns are categorized into four genders: masculine, feminine, neuter, and common.", "True", "False", 2},
        {"The Bulgarian Cyrillic alphabet consists of 32 letters.", "True", "False", 2},
        {"In Bulgarian, the definite article is a suffix that is added to the end of the noun.", "True", "False", 1},
        {"Bulgarian is a Romance language that uses the Cyrillic alphabet.", "True", "False", 2},
        {"Verbs in Bulgarian have three aspects: perfective, imperfective, and subjunctive.", "True", "False", 2},
    };


    srand(static_cast<unsigned int>(time(nullptr)));
    random_shuffle(questions.begin(), questions.end());
    vector<Question> selectedQuestions(questions.begin(), questions.begin() + 10);

    int currentQuestion = 0;
    int score = 0;
    int selectedOption = 0;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE)) selectedOption = 1;
        if (IsKeyPressed(KEY_TWO)) selectedOption = 2;

        if (selectedOption > 0) {
            if (selectedOption == selectedQuestions[currentQuestion].correctOption) {
                score++;
            }
            currentQuestion++;
            selectedOption = 0;
            if (currentQuestion >= 10) break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);
        DrawTextEx(customFont, selectedQuestions[currentQuestion].text.c_str(), { 100, 100 }, 24, 2, WHITE);
        DrawTextEx(customFont, ("1. " + selectedQuestions[currentQuestion].option1).c_str(), { 100, 200 }, 24, 2, BLACK);
        DrawTextEx(customFont, ("2. " + selectedQuestions[currentQuestion].option2).c_str(), { 100, 300 }, 24, 2, BLACK);

        EndDrawing();
    }

    float percentageScore = (score / 10.0f) * 100;
    char scoreText[50];
    sprintf_s(scoreText, "Your Score: %.2f%%", percentageScore);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(scoreText, 960 - MeasureText(scoreText, 20) / 2, 540 - 10, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(customFont);
    CloseWindow();
}