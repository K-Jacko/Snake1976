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
    static void Update();
    static void Draw();
    static void Reset();
    static void CreateTextButtons(const std::vector<GLOBAL::UI::TextButtonData>& textButtonData);
    static void CreateText(const std::vector<GLOBAL::UI::TextData>& textData);
    static std::vector<TextButton*> GetTextButtons();
    static std::vector<Text*> GetText();
    void AddTextToVector(Text m_text);
    static void LoadFirstScene();
    static void LoadSecondScene();
    static void LoadHighScoreScene();
private:
    static std::vector<TextButton*> textButtons;
    static std::vector<Text*> texts;

};

//width/2 , height * 0.22f,