#include "Buttons.h"
#include "WindowLayer.h"
#include "InputLayer.h"

Button::Button() {

}
Button::Button(int m_x, int m_y, ButtonSize m_size, void(*m_action)()) {
    renderer = WindowLayer::Instance().GetRenderer();
    SetSize(m_size);
    buttonState = ButtonState::NORMAL;
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
            buttonState = ButtonState::PRESSED;
            if(!isPressed){
                isPressed = true;
                action();
            }
        }else if(!InputLayer::Instance().LeftIsPressed()){
            buttonState = ButtonState::HOVER;
        }
    }
    else if(!SDL_PointInRect(&point,&shape)){
        buttonState = ButtonState::NORMAL;
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
    buttonState = ButtonState::NORMAL;
    isPressed = false;
    position.y = height = width = position.y = position.x = shape.x = shape.y = shape.w = shape.h = position.x = 0 ;
    action = nullptr;
    text = nullptr;
    fontSize = 0;
}

TextButton::TextButton(int m_x, int m_y, ButtonSize m_size, const char* m_text, GLOBAL::SCREEN::FONT_SIZE m_fontSize, void(*m_action)())
{
    renderer = WindowLayer::Instance().GetRenderer();
    TextButton::SetSize(m_size);
    buttonState = ButtonState::NORMAL;
    isPressed = false;
    position.x = m_x - (width/2);
    position.y = m_y - (height/2);
    shape.x = position.x ;
    shape.y = position.y;
    shape.w = width;
    shape.h = height;
    action = m_action;
    text = m_text;
    fontSize = m_fontSize;

    font = TTF_OpenFont("resources/Pixeboy-z8XGD.ttf", fontSize);

    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }

}

void TextButton::Draw() {
    SDL_Color textColor;
    switch (buttonState) {
        case ButtonState::NORMAL:
            textColor = {255,255,255,255};
            break;
        case ButtonState::HOVER:
            textColor = {100,100,100,255};
            break;
        case ButtonState::PRESSED:
            textColor = {50,50,50,255};
            break;
    }
    if(GLOBAL::DEBUG)
        SDL_RenderFillRect(renderer,&shape);

    textSurface = TTF_RenderText_Solid(font, text, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    if (textSurface == nullptr) {
        SDL_Log("Failed to render text surface: %s", TTF_GetError());
    }
    if (textTexture == nullptr) {
        SDL_Log("Failed to create text texture: %s", SDL_GetError());
    }

    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);

    int centerX = shape.x + (shape.w - textWidth) / 2;
    int centerY = shape.y + (shape.h - textHeight) / 2;


    textRect = { centerX, centerY, textWidth , textHeight };
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
}
