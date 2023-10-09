#pragma once
#include "Global.h"
#include "Text.h"
#include "Buttons.h"
#include "SDL_ttf.h"

class UILayer : public ILayer{
public:
    UILayer() {
        if(TTF_Init() != 0){std::cout << "ERROR" << SDL_GetError() << std::endl;}
        else{std::cout << "Text :: Systems Initialised!" << std::endl;}
    };
    ~UILayer() = default;
    static UILayer& Instance(){
        static UILayer uiLayer;
        return uiLayer;
    };
    void Init() override{};
    void Update() override{
        for (auto &textButton : textButtons) {
            textButton->Update();
        }
        for (auto & text : texts) {
            text->Update();
        }
    };
    void Draw() override{
        for (auto & textButton : textButtons) {
            textButton->Draw();
        }
        for (auto & text : texts) {
            text->Draw();
        }
    };
    void Reset() override{};
    void CreateTextButtons(const std::vector<GLOBAL::UI::TextButtonData>& textButtonData){
        for (const auto & i : textButtonData) {
            auto button = new TextButton(i);
            textButtons.push_back(button);
        }
    };
    void CreateText(const std::vector<GLOBAL::UI::TextData>& textData){
        for (const auto & i : textData) {
            auto text = new Text(i);
            texts.push_back(text);
        }
    };
    std::vector<struct TextButton*> GetTextButtons() {
        return textButtons;
    };
    std::vector<struct Text*> GetText(){
        return texts;
    };
    std::vector<TextButton*> textButtons;
    std::vector<Text*> texts;
private:


};