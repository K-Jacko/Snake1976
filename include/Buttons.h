#pragma once
#include "Global.h"

enum ButtonState{
    NORMAL = 0,
    HOVER = 1,
    PRESSED = 2
};
enum ButtonSize
{
    Tiny,
    Small,
    Medium,
    Large
};
class Button
{
public:
    Button();
    Button(int m_x, int m_y, ButtonSize m_size, void(*m_action)());
    void SetSize(ButtonSize m_size);
    virtual void Update();
    virtual void Draw();
protected:
    ButtonState buttonState;
    SDL_Renderer* renderer;
    SDL_Point position;
    SDL_Rect shape;
    int width, height;
    bool isPressed;
    void(*action)();
};
class TextButton : public Button
{
public:
    TextButton();
    TextButton(int m_x, int m_y, ButtonSize m_size, const char* m_text, GLOBAL::SCREEN::FONT_SIZE fontSize, void(*m_action)());
    void Draw() override;
private:
    const char* text;
    SDL_Rect textRect{};
    int fontSize;
    SDL_Surface* textSurface{};
    SDL_Texture* textTexture{};
    TTF_Font* font;
};