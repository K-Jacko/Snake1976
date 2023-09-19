#pragma once
#include "Global.h"

class Text
{
public:
    Text(GLOBAL::SCREEN::FONT_SIZE m_fontSize, const char* m_text, SDL_Rect m_Box);
    Text(GLOBAL::UI::TextData textData);
    void SetActive(bool active);
    void ChangeText(const char* text);
    void Update();
    void Draw();
    void Reset();
    GLOBAL::GAME::InteractionStatus interactionStatus;
private:
    bool isInteractable = false;
    bool isActive = true;
    const char* string;
    SDL_Renderer* renderer;
    SDL_Rect boxRect = SDL_Rect(1,10,10,10);
    SDL_Rect textRect{};
    int fontSize;
    SDL_Surface* textSurface{};
    SDL_Texture* textTexture{};
    TTF_Font* font;
    SDL_Color textColor = SDL_Color(0,0,0,0);
};