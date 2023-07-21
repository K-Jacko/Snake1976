#pragma once
#include "Global.h"
#include "Buttons.h"

class UILayer
{
public:
    static UILayer& Instance();
    ~UILayer();
    void Init();
    void Update();
    void Draw();
    static void Reset();
    void CreateButtons();
    void AddTextToVector(Text m_text);
    static void LoadFirstScene();
    static void LoadSecondScene();
    static void LoadHighScoreScene();
private:
    static std::vector<TextButton*> uiButtons;
    static std::vector<Text*> texts;
    static TextButton* button1;
    static TextButton* button2;
    static TextButton* button3;
    static TextButton* button4;
    static TextButton* button5;
};

//width/2 , height * 0.22f,