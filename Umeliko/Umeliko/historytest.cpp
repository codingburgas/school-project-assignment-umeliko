#include "historytest.h"

void historytest()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Texture2D background = LoadTexture("../assets/subjectInfo.png");

    Font customFont = LoadFont("../assets/font.ttf");

 

    const char* infoText1 = "test here:";
    
    SetTargetFPS(60);

   

    UnloadTexture(background);
    CloseWindow();
}