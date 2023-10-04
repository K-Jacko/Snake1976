#include "Text.h"
#include "WindowLayer.h"
#include "InputLayer.h"
#include "UILayer.h"
extern "C"{
    extern const unsigned char Pixeboy_z8XGD_ttf[];
    extern const unsigned int Pixeboy_z8XGD_ttf_len;
}
Text::Text(GLOBAL::SCREEN::FONT_SIZE m_fontSize, const char* m_text, SDL_Rect m_Box) {
    renderer = WindowLayer::Instance().GetRenderer();
    string = m_text;
    fontSize = m_fontSize;
    font = TTF_OpenFont("resources/Pixeboy-z8XGD.ttf", fontSize);
    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }
    boxRect = m_Box;
    isInteractable = true;
    textColor = {255,255,255,255};
    textSurface = TTF_RenderText_Solid(font, string, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    interactionStatus = GLOBAL::GAME::InteractionStatus::NORMAL;
}
Text::Text(GLOBAL::UI::TextData textData) {
    renderer = WindowLayer::Instance().GetRenderer();
    string = textData.Text;
    fontSize = textData.FontSize;
    font = TTF_OpenFont("resources/Pixeboy-z8XGD.ttf", fontSize);
    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }
    textColor = {255,255,255,255};
    interactionStatus = GLOBAL::GAME::InteractionStatus::NORMAL;
    switch (fontSize) {
        case GLOBAL::SCREEN::FONT_SIZE::TINY :
            boxRect.w = GLOBAL::SCREEN::FONT_SIZE::TINY;
            boxRect.h = GLOBAL::SCREEN::FONT_SIZE::TINY;
            break;
        case GLOBAL::SCREEN::FONT_SIZE::SMALL :
            boxRect.w = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 + 150;
            boxRect.h = GLOBAL::SCREEN::FONT_SIZE::SMALL * 2 -50;
            break;
        case GLOBAL::SCREEN::FONT_SIZE::MEDIUM :
            boxRect.w = GLOBAL::SCREEN::FONT_SIZE::MEDIUM + 150;
            boxRect.h = GLOBAL::SCREEN::FONT_SIZE::MEDIUM -50;
            break;
        case GLOBAL::SCREEN::FONT_SIZE::LARGE :
            boxRect.w = GLOBAL::SCREEN::FONT_SIZE::LARGE * 2;
            boxRect.h = GLOBAL::SCREEN::FONT_SIZE::LARGE - 100;
            break;
    }
    boxRect.x = textData.XPosition - (boxRect.w/2);
    boxRect.y = textData.YPosition - (boxRect.h/2);
    textSurface = TTF_RenderText_Solid(font, string, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

}
void Text::SetActive(bool active){
    isActive = active;
}
void Text::Update() {
    if(isInteractable && isActive){
//        if (textSurface == nullptr) {
//            SDL_Log("Failed to render string surface: %s", TTF_GetError());
//        }
//        if (textTexture == nullptr) {
//            SDL_Log("Failed to create string texture: %s", SDL_GetError());
//        }

    }
}
void Text::UpdateInteraction(GLOBAL::GAME::InteractionStatus interactionStatus) {
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    textSurface = TTF_RenderText_Solid(font, string, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Point point;
    point.x = InputLayer::Instance().GetMousePosition().x;
    point.y = InputLayer::Instance().GetMousePosition().y;
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
    if(isActive){
        int textWidth, textHeight;
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
        int centerX = boxRect.x + (boxRect.w - textWidth) / 2;
        int centerY = boxRect.y + (boxRect.h - textHeight) / 2;
        textRect = { centerX, centerY, textWidth , textHeight };
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    }
}

void Text::ChangeText(const char* text) {
    string = text;
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    textSurface = TTF_RenderText_Solid(font, string, textColor);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
}





