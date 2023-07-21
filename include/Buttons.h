#pragma once
#include "Global.h"
#include "Text.h"

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
    SDL_Rect shape;
protected:
    GLOBAL::GAME::InteractionStatus buttonState;
    SDL_Renderer* renderer;
    SDL_Point position;
    int width, height;
    bool isPressed;
    void(*action)();
};
class TextButton : public Button
{
public:
    TextButton();
    TextButton(int m_x, int m_y, ButtonSize m_size, const char* m_text, GLOBAL::SCREEN::FONT_SIZE m_fontSize, void(*m_action)());
    void Update() override;
    void Draw() override;
    Text* text;
private:
};