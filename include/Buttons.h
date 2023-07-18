#pragma once
#include "Global.h"

enum ButtonState
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};
enum ButtonSize
{
    Small,
    Medium,
    Large
};
class UIButton
{
public:
    UIButton() = default;
    UIButton(int m_x, int m_y, ButtonSize m_size,const char* m_text);
    void HandleEvent(SDL_Event* m_event);
    void Init(SDL_Renderer* m_renderer);
    void Draw(SDL_Event* m_event);
private:
    SDL_Renderer* renderer;
    SDL_Point position;
    int width, height;
    const char* text;
    ButtonState currentSprite;
};