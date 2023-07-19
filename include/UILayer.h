#pragma once
#include "Global.h"
#include "Buttons.h"
class UILayer
{
public:
    UILayer& Instance();
    ~UILayer();
    void Init(SDL_Renderer* renderer);
    void Update(InputLayer inputLayer);
    void Draw();
    static void Test();
private:
    std::vector<UIButton*> uiButtons;
    UIButton button1;
};