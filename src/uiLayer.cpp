#include "UILayer.h"
#include "Game.h"
#include "Text.h"



std::vector<TextButton*> UILayer::textButtons;
std::vector<Text*> UILayer::texts;


UILayer& UILayer::Instance() {
    static UILayer uiLayer;
    return uiLayer;
}
UILayer::~UILayer() {

}
void UILayer::Init() {

}
void UILayer::Update() {
    for (int i = 0; i < textButtons.size(); ++i) {
        textButtons[i]->Update();
    }
    for (int i = 0; i < texts.size(); ++i) {
        texts[i]->Update();
    }
}
void UILayer::Draw() {
    for (int i = 0; i < textButtons.size(); ++i) {
        textButtons[i]->Draw();
    }
    for (int i = 0; i < texts.size(); ++i) {
        texts[i]->Draw();
    }
//    if(snake != nullptr){
//        snake->Draw();
//    }
}
void UILayer::Reset() {

}

void UILayer::CreateTextButtons(std::vector<GLOBAL::UI::TextButtonData> textButtonData) {
    for (int i = 0; i < textButtonData.size(); ++i) {
        auto button = new TextButton(textButtonData[i]);
        textButtons.push_back(button);
    }
}
void UILayer::AddTextToVector(Text m_text) {

}
void UILayer::LoadFirstScene() {

}
void UILayer::LoadSecondScene() {

}

void UILayer::LoadHighScoreScene(){

}

std::vector<TextButton*> UILayer::GetTextButtons() {
    return textButtons;
}
