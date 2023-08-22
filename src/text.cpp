#include "Text.h"
#include "WindowLayer.h"
#include "InputLayer.h"
#include "UILayer.h"

Text::Text(GLOBAL::SCREEN::FONT_SIZE m_fontSize, const char* m_text, SDL_Rect m_Box) {
    renderer = WindowLayer::Instance().GetRenderer();
    string = m_text;
    fontSize = m_fontSize;
    font = TTF_OpenFont("resources/Pixeboy-z8XGD.ttf", fontSize);
    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }
    boxRect = m_Box;
    interactionStatus = GLOBAL::GAME::InteractionStatus::NORMAL;
}

void Text::LoadText() {

}
void Text::Update() {
    InputLayer& inputLayer = InputLayer::Instance();
    SDL_Point point;
    point.x = InputLayer::Instance().GetMousePosition().x;
    point.y = InputLayer::Instance().GetMousePosition().y;
    if(SDL_PointInRect(&point,&boxRect)){
        if(InputLayer::Instance().LeftIsPressed()){
            interactionStatus = GLOBAL::GAME::InteractionStatus::PRESSED;
        }else if(!InputLayer::Instance().LeftIsPressed()){
            interactionStatus = GLOBAL::GAME::InteractionStatus::HOVER;
        }
    }
    else if(!SDL_PointInRect(&point,&boxRect)){
        interactionStatus = GLOBAL::GAME::InteractionStatus::NORMAL;
    }
    switch (interactionStatus) {
        case GLOBAL::GAME::InteractionStatus::NORMAL:
            textColor = {255,255,255,255};
            break;
        case GLOBAL::GAME::InteractionStatus::HOVER:
            textColor = {100,100,100,255};
            break;
        case GLOBAL::GAME::InteractionStatus::PRESSED:
            textColor = {50,50,50,255};
            break;
    }
}
void Text::Draw() {
    textSurface = TTF_RenderText_Solid(font, string, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    if (textSurface == nullptr) {
        SDL_Log("Failed to render string surface: %s", TTF_GetError());
    }
    if (textTexture == nullptr) {
        SDL_Log("Failed to create string texture: %s", SDL_GetError());
    }

    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);

    int centerX = boxRect.x + (boxRect.w - textWidth) / 2;
    int centerY = boxRect.y + (boxRect.h - textHeight) / 2;


    textRect = { centerX, centerY, textWidth , textHeight };
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}