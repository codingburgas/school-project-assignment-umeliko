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
        {"What political ideologies are covered?", "Socialism and liberalism", "Socialism, conservatism, authoritarianism, and liberalism", 2},
        
        {"Which ideology is considered a hallmark of the modern era?", "Conservatism", "Liberalism", 2},
        
        {"What historical era saw reforms in the Ottoman Empire?", "Renaissance", "Tanzimat era", 2},
        
        {"What was the period of Ottoman Empire reforms?", "1739-1876", "1839-1876", 2},
        
        {"When was the American Constitution ratified?", "1776", "1789", 2},
        
        {"What did the American Constitution establish?", "Autocracy", "Federalism and separation of powers", 2},
        
        {"What is the Bulgarian Revival?", "Political movement", "Cultural awakening", 2},
        
        {"When did the Bulgarian Revival occur?", "Early 18th century", "Early 19th century", 2},
        
        {"Who was Giuseppe Garibaldi?", " Military leader", "Religious figure", 1},
        
        {"What did Giuseppe Garibaldi contribute to in the 19th century?", "Italy's division", "Italy's unification", 2},
        
        {"What ideologies are studied in political ideologies?", "Socialism and conservatism", "Socialism, conservatism, authoritarianism, and liberalism ", 2},
        
        {"Which ideology characterizes the modern era?", "Conservatism", "Liberalism", 2},
        
        {"What period witnessed reforms in the Ottoman Empire?", "Medieval era", "Tanzimat era", 2},
        
        {"When did the Ottoman Empire undergo reforms?", "1700s", "1839-1876", 2},
        
        {"When was the American Constitution ratified?", "1776", "1789", 2},
        
        {"What did the American Constitution establish?", "Monarchy", "Federalism and separation of powers", 2},
        
        {"What does the Bulgarian Revival refer to?", "Political movement", "Cultural awakening", 2},
        
        {"When did the Bulgarian Revival take place?", "Late 18th century", "Early 19th century", 2},
        
        {"Who was Giuseppe Garibaldi?", "Scientist", "Military leader", 2},
        
        {"What was Giuseppe Garibaldi's role in the 19th century?", " Dividing Italy", "Unifying Italy", 2},
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