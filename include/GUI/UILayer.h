#pragma once
#include "Global.h"
#include "Buttons.h"
class UILayer
{
public:
    static UILayer& Instance();
    ~UILayer();
    void Init();
    void Update();
    void Draw();
    static void Test();
private:
    std::vector<TextButton*> uiButtons;
    TextButton button1;
    TextButton button2;
    TextButton button3;
    TextButton button4;
};