#include "historyTest.h"
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

void historyTest()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Umeliko");

    Texture2D background = LoadTexture("../assets/subjectInfo.png");
    Font customFont = LoadFont("../assets/font.ttf");

    SetTargetFPS(60);


    vector<Question> questions = {
        {"Socialism advocates for the collective ownership of the means of production.", "True", "False", 1},
        {"Conservatism typically emphasizes maintaining traditional institutions and values.", "True", "False", 1},
        {"Authoritarianism prioritizes individual liberties and freedoms.", "True", "False", 2},
        {"Liberalism is a prominent political ideology in contemporary society.", "True", "False", 1},
        {"The Tanzimat era saw the Ottoman Empire implementing modernizing reforms.", "True", "False", 1},
        {"The Ottoman Empire underwent reforms from 1839 to 1876.", "True", "False", 1},
        {"The American Constitution was ratified in 1889.", "True", "False", 2},
        {"The American Constitution established federalism and the separation of powers.", "True", "False", 1},
        {"The Bulgarian Revival refers to a cultural awakening in the late 19th century.", "True", "False", 2},
        {"Giuseppe Garibaldi played a significant role in Germany's unification in the 19th century.", "True", "False", 2},
        {"Socialism advocates for a free - market economy.", "True", "False", 2},
        {"Conservatism emphasizes radical societal changes.", "True", "False", 2},
        {"Authoritarianism prioritizes individual freedoms over state control.", "True", "False", 2},
        {"Liberalism promotes limited government intervention in the economy.", "True", "False", 1},
        {"The Tanzimat era occurred during the late 17th century.", "True", "False", 2},
        {"The American Constitution was established in the 18th century.", "True", "False", 1},
        {"The Bulgarian Revival occurred during the Renaissance period.", "True", "False", 2},
        {"Giuseppe Garibaldi played a crucial role in Italy's unification in the 19th century.", "True", "False", 1},
        {"Socialism advocates for a classless society.", "True", "False", 1},
        {"Conservatism opposes the preservation of traditional values.", "True", "False", 2},
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