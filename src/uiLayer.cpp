#include "UILayer.h"
#include "Game.h"
#include "Text.h"
#include "Buttons.h"



std::vector<TextButton*> UILayer::textButtons;
std::vector<Text*> UILayer::texts;

UILayer::UILayer() {

}

UILayer& UILayer::Instance() {
    static UILayer uiLayer;
    return uiLayer;
}
UILayer::~UILayer() = default;
void UILayer::Init() {

}
void UILayer::Update() {
    for (auto & textButton : textButtons) {
        textButton->Update();
    }
    for (auto & text : texts) {
        text->Update();
    }
}
void UILayer::Draw() {
    for (auto & textButton : textButtons) {
        textButton->Draw();
    }
    for (auto & text : texts) {
        text->Draw();
    }
}
void UILayer::Reset() {

}

void UILayer::CreateTextButtons(const std::vector<GLOBAL::UI::TextButtonData>& textButtonData) {
    for (const auto & i : textButtonData) {
        auto button = new TextButton(i);
        textButtons.push_back(button);
    }
}
void UILayer::CreateText(const std::vector<GLOBAL::UI::TextData>& textData) {
    for (const auto & i : textData) {
        auto text = new Text(i);
        texts.push_back(text);
    }
}
std::vector<TextButton*> UILayer::GetTextButtons() {
    return textButtons;
}

std::vector<Text *> UILayer::GetText() {
    return texts;
}




