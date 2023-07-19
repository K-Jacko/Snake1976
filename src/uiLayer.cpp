#include "UILayer.h"


UILayer& UILayer::Instance() {
    static UILayer uiLayer;
    return uiLayer;
}
UILayer::~UILayer() {
    uiButtons.clear();
    uiButtons.shrink_to_fit();
}

void UILayer::Init(SDL_Renderer* renderer) {
    button1 = UIButton(GLOBAL::SCREEN::WIDTH / 2 , GLOBAL::SCREEN::HEIGHT * 0.33f, ButtonSize::Large, "Start",GLOBAL::SCREEN::FONT_SIZE::LARGE, Test);
    button2 = UIButton(GLOBAL::SCREEN::WIDTH / 2 , GLOBAL::SCREEN::HEIGHT * 0.33f + 100, ButtonSize::Small, "> Highscores",GLOBAL::SCREEN::FONT_SIZE::SMALL, Test);
    button1.Init(renderer);
    button2.Init(renderer);
    uiButtons.push_back(&button1);
    uiButtons.push_back(&button2);
}

void UILayer::Update(InputLayer inputLayer) {
    for (UIButton* buttons : uiButtons) {
        buttons->Update(&inputLayer);
    }
}

void UILayer::Draw() {

    for (UIButton* buttons : uiButtons) {
        buttons->Draw();
    }
}

void UILayer::Test() {
    std::cout << "Clicked" << std::endl;

}