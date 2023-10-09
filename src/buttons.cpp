#include "Buttons.h"
#include "./layers/WindowLayer.h"
#include "./layers/InputLayer.h"

SDL_Event EventLayer::event;

Button::Button() {

}
Button::Button(int m_x, int m_y, GLOBAL::UI::ButtonSize m_size) {
    renderer = WindowLayer::Instance().GetRenderer();
    SetSize(m_size);
    buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
    shape = SDL_Rect(m_x,m_y,10,10);
    position = SDL_Point() ;
    isActive = true;
}
void Button::Update() {
    if(isActive){
        SDL_Point point;
        point.x = InputLayer::Instance().GetMousePosition().x;
        point.y = InputLayer::Instance().GetMousePosition().y;
        if(SDL_PointInRect(&point,&shape)){
            if(InputLayer::Instance().LeftIsPressed()){
                buttonState = GLOBAL::GAME::InteractionStatus::PRESSED;
                SDL_PushEvent(&buttonEvent);
            }else if(!InputLayer::Instance().LeftIsPressed()){
                buttonState = GLOBAL::GAME::InteractionStatus::HOVER;
            }
        }
        else if(!SDL_PointInRect(&point,&shape)){
            buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
        }
    }
}
void Button::Draw() {

}
void Button::SetSize(GLOBAL::UI::ButtonSize m_size) {
    switch (m_size) {
        case GLOBAL::UI::ButtonSize::Small:
            width = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 + 150;
            height = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 -50;
            break;
        case GLOBAL::UI::ButtonSize::Medium:
            width = GLOBAL::SCREEN::FONT_SIZE::MEDIUM + 150;
            height = GLOBAL::SCREEN::FONT_SIZE::MEDIUM -50;
            break;
        case GLOBAL::UI::ButtonSize::Large:
            width = GLOBAL::SCREEN::FONT_SIZE::LARGE * 2;
            height = GLOBAL::SCREEN::FONT_SIZE::LARGE - 100;
            break;
        case GLOBAL::UI::Tiny:
            width = GLOBAL::SCREEN::FONT_SIZE::TINY;
            height = GLOBAL::SCREEN::FONT_SIZE::TINY;
            break;
    }
}

void Button::SetupEvent(int userCode) {

}

bool Button::GetActive() {return isActive;}

void Button::SetActive(bool m_active) {isActive = m_active;}

TextButton::TextButton() {
    buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
    position.y = height = width = position.y = position.x = shape.x = shape.y = shape.w = shape.h = position.x = 0 ;

}
TextButton::TextButton(GLOBAL::UI::TextButtonData m_data) {
    renderer = WindowLayer::Instance().GetRenderer();
    TextButton::SetSize(m_data.Size);
    buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
    isActive = true;
    position.x = m_data.XPosition - (width/2);
    position.y = m_data.YPosition - (height/2);
    shape.x = position.x;
    shape.y = position.y;
    shape.w = width;
    shape.h = height;
    text = new Text(m_data.FontSize,m_data.Text,shape);
    buttonEvent.type = SDL_USEREVENT;
    buttonEvent.user.code = m_data.EventCode;
    soundClip = Mix_LoadWAV(m_data.SoundClipPath);
    if(soundClip == NULL){
        std::cout << "ERROR : Audio error" << Mix_GetError() << std::endl;
    }
    soundEvent.type = SDL_USEREVENT;
    soundEvent.user.code = 200;
    soundEvent.user.data1 = soundClip;
}
void TextButton::Update() {
    if(isActive){
        SDL_Point point;
        point.x = InputLayer::Instance().GetMousePosition().x;
        point.y = InputLayer::Instance().GetMousePosition().y;
        if(SDL_PointInRect(&point,&shape)){
            if(InputLayer::Instance().LeftIsPressed()){
                buttonState = GLOBAL::GAME::InteractionStatus::PRESSED;
                SDL_PushEvent(&buttonEvent);
                SDL_PushEvent(&soundEvent);

            }else if(!InputLayer::Instance().LeftIsPressed()){
                buttonState = GLOBAL::GAME::InteractionStatus::HOVER;
            }
        }
        else if(!SDL_PointInRect(&point,&shape)){
            buttonState = GLOBAL::GAME::InteractionStatus::NORMAL;
        }
        text->UpdateInteraction(buttonState);
    }
}
void TextButton::Draw() {
    if(isActive){
        switch (buttonState) {
            case GLOBAL::GAME::InteractionStatus::HOVER :
                SDL_SetRenderDrawColor(renderer,0,255,0,255);
                break;
            case GLOBAL::GAME::InteractionStatus::PRESSED :
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                break;
            case GLOBAL::GAME::InteractionStatus::NORMAL :
                SDL_SetRenderDrawColor(renderer,255,0,0,255);
                break;
        }
#ifdef NDEBUG
        SDL_RenderDrawRect(renderer,&shape);
#endif
        //SDL_SetRenderDrawColor(renderer,0,0,0,255);
        text->Draw();
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
    }
}


