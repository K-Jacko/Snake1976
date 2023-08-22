#pragma once
#include "Global.h"
#include "Buttons.h"
#include "snake1976/Snake.h"

class UILayer
{
public:
    static UILayer& Instance();
    ~UILayer();
    void Init();
    void Update();
    void Draw();
    static void Reset();
    void CreateTextButtons(std::vector<GLOBAL::UI::TextButtonData> textButtonData);
    std::vector<TextButton*> GetTextButtons();
    void AddTextToVector(Text m_text);
    static void LoadFirstScene();
    static void LoadSecondScene();
    static void LoadHighScoreScene();
private:
    static std::vector<TextButton*> textButtons;
    static std::vector<Text*> texts;

};

//width/2 , height * 0.22f,