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
    button1 = UIButton(Global::SCREEN::WIDTH/2 - 100,100,ButtonSize::Medium,"Test",Test);
    button1.Init(renderer);
    uiButtons.push_back(&button1);
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