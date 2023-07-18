#include "Buttons.h"

UIButton::UIButton(int m_x, int m_y, ButtonSize m_size, const char* m_text)
{
    position.x = m_x * Global::SCREEN::CELL_SIZE;
    position.y = m_y * Global::SCREEN::CELL_SIZE;
    switch (m_size) {
        case ButtonSize::Small:
            width = height = 100;
            break;
        case ButtonSize::Medium:
            width = 200;
            height = 100;
            break;
        case ButtonSize::Large:
            width = height = 400;
            break;
    }


    currentSprite = BUTTON_SPRITE_MOUSE_OUT;
}
void UIButton::Init(SDL_Renderer* m_renderer){
    renderer = m_renderer;
}
void UIButton::Draw(SDL_Event* m_event) {
    SDL_Rect rc;
    rc.x = position.x ;
    rc.y = position.y;
    rc.w = width;
    rc.h = height;

    //SDL_RenderDrawRect(renderer, &rc);
    switch (currentSprite) {
        case BUTTON_SPRITE_MOUSE_OVER_MOTION:
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
            break;
        case BUTTON_SPRITE_MOUSE_DOWN:
            SDL_SetRenderDrawColor(renderer,0,255,0,255);
            break;
        case BUTTON_SPRITE_MOUSE_UP:
            SDL_SetRenderDrawColor(renderer,0,0,255,255);
            break;
        case BUTTON_SPRITE_MOUSE_OUT:
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            break;
        case BUTTON_SPRITE_TOTAL:
            break;
    }

    SDL_RenderFillRect(renderer,&rc);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

}
void UIButton::SetPosition(int m_x, int m_y) {
    position.x = m_x;
    position.y = m_y;
}

void UIButton::HandleEvent(SDL_Event* m_event )
{

}