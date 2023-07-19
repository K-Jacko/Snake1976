#include "Buttons.h"

UIButton::UIButton(int m_x, int m_y, ButtonSize m_size, const char* m_text,void(*m_action)())
{
    buttonState = ButtonState::NORMAL;
    position.x = m_x ;
    position.y = m_y ;
    switch (m_size) {
        case ButtonSize::Small:
            width = height = 100;
            break;
        case ButtonSize::Medium:
            width = 200;
            height = 100;
            break;
        case ButtonSize::Large:
            width = height = 400;
            break;
    }
    shape.x = position.x ;
    shape.y = position.y;
    shape.w = width;
    shape.h = height;
    action = m_action;
    std::cout << position.x << " " << position.y << std::endl;
}
void UIButton::Init(SDL_Renderer* m_renderer){
    renderer = m_renderer;
}
void UIButton::Update(InputLayer* inputLayer){
    SDL_Point point = SDL_Point(inputLayer->Instance().GetMousePosition()->x,inputLayer->Instance().GetMousePosition()->y);

    if(SDL_PointInRect(&point,&shape)){
        if(inputLayer->Instance().LeftIsPressed()){
            buttonState = ButtonState::PRESSED;
            action();
        }else if(!inputLayer->Instance().LeftIsPressed()){
            buttonState = ButtonState::HOVER;
        }
    }
    else if(!SDL_PointInRect(&point,&shape)){
        buttonState = ButtonState::NORMAL;
    }
}
void UIButton::Draw() {
    switch (buttonState) {
        case ButtonState::NORMAL:
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
            break;
        case ButtonState::HOVER:
            SDL_SetRenderDrawColor(renderer,0,255,0,255);
            break;
        case ButtonState::PRESSED:
            SDL_SetRenderDrawColor(renderer,0,0,255,255);
            break;

    }

    SDL_RenderFillRect(renderer,&shape);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

}

void UIButton::HandleEvent(SDL_Event* m_event )
{

}