#pragma once
#include "Global.h"

class FoodCell{
public:
    FoodCell(GLOBAL::MATH::Vector2D m_position)
    :position(m_position){}
    GLOBAL::MATH::Vector2D position;
    void Update(){

    };
private:
    //On spawn Check within bounds
    //On spawn Check Not on snakes body
    //On Update Check if OnHead
};