#include "biologyTest.h"
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

void biologyTest()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Umeliko");

    Texture2D background = LoadTexture("../assets/subjectInfo.png");
    Font customFont = LoadFont("../assets/font.ttf");

    SetTargetFPS(60);


    vector<Question> questions = {
        {"During photosynthesis, what do plants use to produce glucose and oxygen?", "Carbon dioxide and water", "Oxygen and sunlight", 1}, 
        
        {"What organelles generate energy for the cell through cellular respiration?", "Mitochondria", " Chloroplasts", 1},
        
        {"What are viruses primarily composed of?", " Cells", "Genetic material surrounded by a protein coat ", 2},
        
        {"How many bones does an adult human typically have?", "106 bones", "206 bones", 2},
        
        {"What survival strategy do some animals adopt to conserve energy during periods of food scarcity?", "Hibernation", "Migration", 1},
        
        {"During photosynthesis, what substances are used to produce glucose and oxygen?", " Oxygen and sunlight", " Carbon dioxide and water", 2},
        
        {"Which organelles generate energy for the cell through cellular respiration?", "Nucleus b", "Mitochondria", 2},
        
        {"What is the primary composition of viruses?", " Cells", "Genetic material surrounded by a protein coat", 2},
        
        {"What is the survival strategy adopted by some animals to conserve energy during periods of food scarcity?", "Migration", "Hibernation", 2},
        
        {"What process do plants use to produce glucose and oxygen?", "Respiration", "Photosynthesis", 2},
        
        {"Which cellular organelles generate energy for the cell?", "Ribosomes", "Mitochondria", 2},
        
        {"What strategy do some animals adopt to conserve energy during periods of food scarcity?", "Hibernation", "Migration", 1},
        
        {"What organelles are responsible for synthesizing proteins within the cell?", "Ribosomes", " Golgi apparatus", 1},
        
        {"Which organelles contain enzymes that break down waste materials within the cell?", "Lysosomes", "Mitochondria", 1},
        
        {"What organelles are responsible for packaging and sorting proteins for transport within the cell?", "Ribosomes", "Golgi apparatus", 2},
        
        {"Which organelles are involved in lipid synthesis and detoxification of harmful substances within the cell?", "Endoplasmic reticulum", " Chloroplasts", 1},
        
        {"What organelles contain chlorophyll and are responsible for photosynthesis in plant cells?", "Nucleus", "Chloroplasts", 2},
        
        {"Which organelles regulate cell division and contain the cell's genetic material?", "Nucleus", "Vacuoles", 1},
        
        {"What organelles are involved in maintaining cell shape, providing structural support, and facilitating cell movement?", "Cytoskeleton", "Endoplasmic reticulum", 1},
        
        {"Which organelles are responsible for the synthesis of ATP through cellular respiration?", "Ribosomes", "Mitochondria", 2},
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