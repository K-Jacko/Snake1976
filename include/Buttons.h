#pragma once
#include "Global.h"
#include "Text.h"

class Button
{
public:
    Button();
    Button(int m_x, int m_y, GLOBAL::UI::ButtonSize m_size, void(*m_action)());
    void SetSize(GLOBAL::UI::ButtonSize m_size);
    virtual void Update();
    virtual void Draw();
    virtual void SetAction(void(*m_action)());
    void SetActive(bool m_active);
    bool GetActive();
    SDL_Rect shape;
protected:
    GLOBAL::GAME::InteractionStatus buttonState;
    SDL_Renderer* renderer;
    SDL_Point position;
    int width, height;
    bool isPressed, isActive;
    void(*action)();
};
class TextButton : public Button
{
public:
    TextButton();
    TextButton(GLOBAL::UI::TextButtonData m_data);
    void Update() override;
    void Draw() override;
    Text* text;
private:
};