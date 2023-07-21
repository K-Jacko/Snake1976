#include "UILayer.h"
#include "Game.h"
#include "Text.h"

TextButton* UILayer::button1;
TextButton* UILayer::button2;
TextButton* UILayer::button3;
TextButton* UILayer::button4;
TextButton* UILayer::button5;






std::vector<TextButton*> UILayer::uiButtons;
std::vector<Text*> UILayer::texts;

UILayer& UILayer::Instance() {
    static UILayer uiLayer;
    return uiLayer;
}
UILayer::~UILayer() {
    for (TextButton* buttons : uiButtons){
        delete buttons;
    }
    uiButtons.clear();
    uiButtons.shrink_to_fit();
    for (Text* text : texts) {
        delete text;
    }
    texts.clear();
    texts.shrink_to_fit();
}
void UILayer::Init() {
    CreateButtons();
    LoadFirstScene();
}
void UILayer::Update() {
    for (TextButton* buttons : uiButtons){
        buttons->Update();
    }
    for (Text* text : texts) {
        text->Update();
    }
}
void UILayer::Draw() {

    for (TextButton* buttons : uiButtons) {
        buttons->Draw();
    }
    for (Text* text : texts) {
        text->Draw();
    }
}
void UILayer::Reset() {
    uiButtons.clear();
    uiButtons.shrink_to_fit();
    texts.clear();
    texts.shrink_to_fit();
}
void UILayer::CreateButtons() {
    button1 = new TextButton(GLOBAL::SCREEN::SCREEN_WIDTH / 2 , GLOBAL::SCREEN::SCREEN_HEIGHT * 0.22f, ButtonSize::Large , "Snake", GLOBAL::SCREEN::FONT_SIZE::LARGE, nullptr);
    button2 = new TextButton(GLOBAL::SCREEN::SCREEN_WIDTH / 2 , GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f, ButtonSize::Medium , "Start", GLOBAL::SCREEN::FONT_SIZE::MEDIUM,  LoadSecondScene);
    button3 = new TextButton(GLOBAL::SCREEN::SCREEN_WIDTH / 2 , GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f + 100, ButtonSize::Small,"> HighScores", GLOBAL::SCREEN::FONT_SIZE::SMALL, LoadHighScoreScene);
    button4 = new TextButton(GLOBAL::SCREEN::SCREEN_WIDTH - 25 , 25, ButtonSize::Tiny,"X", GLOBAL::SCREEN::FONT_SIZE::SMALL,  Game::End);
    button5 = new TextButton(25 , 25, ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL, LoadFirstScene);
}
void UILayer::AddTextToVector(Text m_text) {
}
void UILayer::LoadFirstScene() {
    Reset();
    uiButtons.push_back(button1);
    uiButtons.push_back(button2);
    uiButtons.push_back(button3);
    uiButtons.push_back(button4);
    GridLayer::Instance().LoadNewGrid(15,20,48);
}
void UILayer::LoadSecondScene() {
    Reset();
    uiButtons.push_back(button5);
    GridLayer::Instance().LoadNewGrid(30,40,24);
}

void UILayer::LoadHighScoreScene(){
    Reset();
    uiButtons.push_back(button4);
    uiButtons.push_back(button5);
    GridLayer::Instance().LoadNewGrid(15,10,48);
}