#pragma once
#include "Global.h"

class Text
{
public:
    Text(GLOBAL::SCREEN::FONT_SIZE m_fontSize, const char* m_text, SDL_Rect m_Box);
    void LoadText();
    void Update();
    void Draw();
    void Reset();
    GLOBAL::GAME::InteractionStatus interactionStatus;
private:
    const char* string;
    SDL_Renderer* renderer;
    SDL_Rect boxRect;
    SDL_Rect textRect{};
    int fontSize;
    SDL_Surface* textSurface{};
    SDL_Texture* textTexture{};
    TTF_Font* font;
    SDL_Color textColor;
};