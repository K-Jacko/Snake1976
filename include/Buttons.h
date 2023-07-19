#pragma once
#include "Global.h"
#include "InputLayer.h"

enum ButtonState{
    NORMAL = 0,
    HOVER = 1,
    PRESSED = 2
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
    UIButton(int m_x, int m_y, ButtonSize m_size,const char* m_text,void(*m_action)());
    void HandleEvent(SDL_Event* m_event);
    void Update(InputLayer* inputLayer);
    void Init(SDL_Renderer* m_renderer);
    void Draw();
private:
     ButtonState buttonState;
    void(*action)();
    SDL_Renderer* renderer{};
    SDL_Point position{};
    SDL_Rect shape{};
    int width, height;
    const char* text{};
};