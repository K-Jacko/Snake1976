#pragma once
#include "Global.h"

class UILayer
{
public:
    UILayer();
    ~UILayer();
    static UILayer& Instance();
    void Init();
    void Update();
    void Draw();
    void Reset();
    void CreateTextButtons(const std::vector<GLOBAL::UI::TextButtonData>& textButtonData);
    void CreateText(const std::vector<GLOBAL::UI::TextData>& textData);
    std::vector<struct TextButton*> GetTextButtons();
    std::vector<struct Text*> GetText();
private:
    static std::vector<TextButton*> textButtons;
    static std::vector<Text*> texts;

};

//width/2 , height * 0.22f,