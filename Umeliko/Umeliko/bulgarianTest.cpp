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
        {"What are nouns categorized into in Bulgarian?", "Masculine, feminine, and common", "Masculine, feminine, and neuter", 2}, 
        
        {"How many letters are there in the Bulgarian Cyrillic alphabet?", "26 letters", "30 letters", 2}, 
        
        {"How is the definite article used in Bulgarian grammar?", "As a prefix added to the beginning of the noun", "As a suffix added to the end of the noun", 2},
        
        {"Is Bulgarian written using the Cyrillic or Latin alphabet?", " Latin alphabet", "Cyrillic alphabet", 2},
        
        {"How many aspects do verbs have in Bulgarian?", "One", "Two", 2},
        
        {"In Bulgarian, how are nouns classified?", "Masculine, feminine, and neutral", "Masculine, feminine, and neuter", 2},
        
        {"How many letters are there in the Bulgarian Cyrillic alphabet?", "25 letters", "30 letters", 2},
        
        {"In Bulgarian grammar, where is the definite article placed?", "In front of the noun", "At the end of the noun", 2},
        
        {"Is Bulgarian written using the Latin or Cyrillic alphabet?", " Latin alphabet", "Cyrillic alphabet", 2},
        
        {"How many aspects do Bulgarian verbs typically have?", "Singular", "Two", 2},
        
        {"In Bulgarian, how are nouns divided into categories?", "Masculine, feminine, and common", "Masculine, feminine, and neuter", 2},
        
        {"How many letters does the Bulgarian Cyrillic alphabet comprise?", "26 letters", "30 letters", 2},
        
        {"Where does the definite article usually appear in Bulgarian grammar?", "Before the noun", "After the noun", 2},
        
        {"Is Bulgarian typically written using the Latin or Cyrillic alphabet?", "Latin alphabet", "Cyrillic alphabet", 2},
        
        {"How many aspects do Bulgarian verbs possess?", "One", "Two", 2},
        
        {"In Bulgarian, how are nouns classified?", "Masculine, feminine, and common", "Masculine, feminine, and neuter", 2},
        
        {"How many letters does the Bulgarian Cyrillic alphabet consist of?", "25 letters", "30 letters", 2},
        
        {"In Bulgarian grammar, where does the definite article attach?", "In front of the noun", "After the noun", 2},
        
        {"Is Bulgarian typically written using the Latin or Cyrillic alphabet?", "Latin alphabet", "Cyrillic alphabet", 2},
        
        {"How many aspects do Bulgarian verbs usually have?", "Singular", "Two", 2},
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