#include "geographyTest.h"
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

void geographyTest()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Umeliko");

    Texture2D background = LoadTexture("../assets/subjectInfo.png");
    Font customFont = LoadFont("../assets/font.ttf");

    SetTargetFPS(60);


    vector<Question> questions = {
        {"What is the capital of France?", "Paris", "London", 1},
        
        {"Which mountain is the tallest above sea level?", "Mount Everest", "Mount Kilimanjaro", 1},
        
        {"What is the largest hot desert globally?", "Sahara Desert", "Gobi Desert", 1},
        
        {"Which river is the longest in the world?", "Nile River", " Amazon River", 1},
        
        {"Which continent is the smallest and also the name of a country?", "Australia", "Asia", 1},
        
        {"What is the capital of France?", "London", "Paris", 2},
        
        {"Which mountain is the tallest above sea level?", "Mount Kilimanjaro", "Mount Everest", 2},
        
        {"What is the largest hot desert globally?", "Gobi Desert", "Sahara Desert", 2},
        
        {"Which river is the longest in the world?", "Amazon River", "Nile River", 2},
        
        {"Which continent is the smallest and also the name of a country?", "Asia", "Australia", 2},
        
        {"What is the capital of France?", "Paris", "New York", 1},
        
        {"Which mountain is the tallest above sea level?", "Mount Everest", "Mount Fuji", 1},
        
        {"What is the largest hot desert globally?", " Sahara Desert", "Atacama Desert", 1},
        
        {"Which river is the longest in the world?", " Amazon River", "Nile River", 2},
        
        {"Which continent is the smallest and also the name of a country?", "Europe", "Australia", 2},
        
        {"What is the capital of France?", "Paris", "Beijing", 1},
        
        {"Which mountain is the tallest above sea level?", "Mount Everest", "Mount McKinley", 1},
        
        {"What is the largest hot desert globally?", "Sahara Desert", "Kalahari Desert", 1},
        
        {"Which river is the longest in the world?", "Amazon River", "Nile River", 2},
        
        {"Which continent is the smallest and also the name of a country?", "Africa", "Australia", 2},
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