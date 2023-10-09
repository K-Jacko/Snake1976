#pragma once
#include "Global.h"
#include "Text.h"
#include "SDL_mixer.h"

class Button
{
public:
    Button();
    Button(int m_x, int m_y, GLOBAL::UI::ButtonSize m_size);
    void SetSize(GLOBAL::UI::ButtonSize m_size);
    virtual void Update();
    virtual void Draw();
    virtual void SetupEvent(int userCode);
    void SetActive(bool m_active);
    bool GetActive();
    SDL_Rect shape;
protected:
    GLOBAL::GAME::InteractionStatus buttonState;
    SDL_Renderer* renderer;
    SDL_Point position;
    int width, height;
    bool isActive;
    SDL_Event buttonEvent;
    SDL_Event soundEvent;
    Mix_Chunk* soundClip;
};
class TextButton : public Button
{
public:
    TextButton();
    explicit TextButton(GLOBAL::UI::TextButtonData m_data);
    void Update() override;
    void Draw() override;
    Text* text = nullptr;
private:
};