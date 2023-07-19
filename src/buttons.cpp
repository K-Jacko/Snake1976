#include "Buttons.h"

UIButton::UIButton(int m_x, int m_y, ButtonSize m_size, const char* m_text,GLOBAL::SCREEN::FONT_SIZE m_fontSize,void(*m_action)())
{
    buttonState = ButtonState::NORMAL;
    isPressed = false;
    switch (m_size) {
        case ButtonSize::Small:
            width = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 + 150;
            height = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 -50;
            break;
        case ButtonSize::Medium:
            width = 200;
            height = 100;
            break;
        case ButtonSize::Large:
            width = GLOBAL::SCREEN::FONT_SIZE::LARGE * 2;
            height = GLOBAL::SCREEN::FONT_SIZE::LARGE -100;
            break;
    }
    position.x = m_x - (width/2);
    position.y = m_y - (height/2);
    shape.x = position.x ;
    shape.y = position.y;
    shape.w = width;
    shape.h = height;
    action = m_action;
    text = m_text;
    fontSize = m_fontSize;
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
            if(!isPressed){
                action();
                isPressed = true;
            }
        }else if(!inputLayer->Instance().LeftIsPressed()){
            buttonState = ButtonState::HOVER;
            isPressed = false;
        }
    }
    else if(!SDL_PointInRect(&point,&shape)){
        buttonState = ButtonState::NORMAL;
        isPressed = false;
    }
}
void UIButton::Draw() {
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

    TTF_Font* font = TTF_OpenFont("resources/Pixeboy-z8XGD.ttf", fontSize);
    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }


    // Render the text

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == nullptr) {
        SDL_Log("Failed to render text surface: %s", TTF_GetError());
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
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

void UIButton::HandleEvent(SDL_Event* m_event )
{

}