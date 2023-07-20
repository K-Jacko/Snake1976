#include "GUI/UILayer.h"
#include "Game.h"


UILayer& UILayer::Instance() {
    static UILayer uiLayer;
    return uiLayer;
}
UILayer::~UILayer() {
    uiButtons.clear();
    uiButtons.shrink_to_fit();
}

void UILayer::Init() {
    SDL_Renderer* renderer = WindowLayer::Instance().GetRenderer();
    button1 = TextButton(GLOBAL::SCREEN::SCREEN_WIDTH / 2 , GLOBAL::SCREEN::SCREEN_HEIGHT * 0.22f, ButtonSize::Large, "Snake", GLOBAL::SCREEN::FONT_SIZE::LARGE, Test);
    button2 = TextButton(GLOBAL::SCREEN::SCREEN_WIDTH / 2 , GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f, ButtonSize::Medium, "Start", GLOBAL::SCREEN::FONT_SIZE::MEDIUM, Test);
    button3 = TextButton(GLOBAL::SCREEN::SCREEN_WIDTH / 2 , GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f + 100, ButtonSize::Small, "> HighScores", GLOBAL::SCREEN::FONT_SIZE::SMALL, Test);
    button4 = TextButton(GLOBAL::SCREEN::SCREEN_WIDTH - 25 , 25, ButtonSize::Tiny, "X", GLOBAL::SCREEN::FONT_SIZE::SMALL, Game::End);
    uiButtons.push_back(&button1);
    uiButtons.push_back(&button2);
    uiButtons.push_back(&button3);
    uiButtons.push_back(&button4);
}

void UILayer::Update() {
    for (TextButton* buttons : uiButtons) {
        buttons->Update();
    }
}

void UILayer::Draw() {

    for (TextButton* buttons : uiButtons) {
        buttons->Draw();
    }
}

void UILayer::Test() {
    std::cout << "Clicked" << std::endl;

}