#include "Buttons.h"
#include "WindowLayer.h"
#include "InputLayer.h"
#include "UILayer.h"

Button::Button() {

}
Button::Button(int m_x, int m_y, ButtonSize m_size, void(*m_action)()) {
    renderer = WindowLayer::Instance().GetRenderer();
    SetSize(m_size);
    buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
    shape = SDL_Rect();
    position = SDL_Point() ;
    isPressed = false;
    action = m_action;
}
void Button::Update() {
    InputLayer& inputLayer = InputLayer::Instance();
    SDL_Point point;
    point.x = InputLayer::Instance().GetMousePosition().x;
    point.y = InputLayer::Instance().GetMousePosition().y;
    if(SDL_PointInRect(&point,&shape)){
        if(InputLayer::Instance().LeftIsPressed()){
            buttonState = GLOBAL::GAME::InteractionStatus::PRESSED;
            if(!isPressed){
                isPressed = true;
                action();
            }
        }else if(!InputLayer::Instance().LeftIsPressed()){
            buttonState = GLOBAL::GAME::InteractionStatus::HOVER;
        }
    }
    else if(!SDL_PointInRect(&point,&shape)){
        buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
        isPressed = false;
    }
}
void Button::Draw() {

}
void Button::SetSize(ButtonSize m_size) {
    switch (m_size) {
        case ButtonSize::Small:
            width = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 + 150;
            height = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 -50;
            break;
        case ButtonSize::Medium:
            width = GLOBAL::SCREEN::FONT_SIZE::MEDIUM + 150;
            height = GLOBAL::SCREEN::FONT_SIZE::MEDIUM -50;
            break;
        case ButtonSize::Large:
            width = GLOBAL::SCREEN::FONT_SIZE::LARGE * 2;
            height = GLOBAL::SCREEN::FONT_SIZE::LARGE - 100;
            break;
        case Tiny:
            width = GLOBAL::SCREEN::FONT_SIZE::TINY;
            height = GLOBAL::SCREEN::FONT_SIZE::TINY;
            break;
    }
}

TextButton::TextButton() {
    buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
    isPressed = false;
    position.y = height = width = position.y = position.x = shape.x = shape.y = shape.w = shape.h = position.x = 0 ;
    action = nullptr;
}

TextButton::TextButton(int m_x, int m_y, ButtonSize m_size, const char* m_text, GLOBAL::SCREEN::FONT_SIZE m_fontSize, void(*m_action)()){
    renderer = WindowLayer::Instance().GetRenderer();
    TextButton::SetSize(m_size);
    buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
    isPressed = false;
    position.x = m_x - (width/2);
    position.y = m_y - (height/2);
    shape.x = position.x ;
    shape.y = position.y;
    shape.w = width;
    shape.h = height;
    action = m_action;
    text = new Text(m_fontSize,m_text,shape);
}
void TextButton::Update() {
    text->Update();
    InputLayer& inputLayer = InputLayer::Instance();
    SDL_Point point;
    point.x = InputLayer::Instance().GetMousePosition().x;
    point.y = InputLayer::Instance().GetMousePosition().y;
    if(SDL_PointInRect(&point,&shape)){
        if(InputLayer::Instance().LeftIsPressed()){
            buttonState = GLOBAL::GAME::InteractionStatus::PRESSED;
            if(!isPressed){
                isPressed = true;
                action();
            }
        }else if(!InputLayer::Instance().LeftIsPressed()){
            buttonState = GLOBAL::GAME::InteractionStatus::HOVER;
        }
    }
    else if(!SDL_PointInRect(&point,&shape)){
        buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
        isPressed = false;
    }
}

void TextButton::Draw() {
    SDL_RenderFillRect(renderer,&shape);
    text->Draw();
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
}
