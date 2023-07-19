#pragma once
#include <SDL.h>
#include "SDL_ttf.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <memory>

namespace GLOBAL
{
#ifdef NDEBUG
// Debugging information is enabled
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

    namespace GAME{
        enum class Direction{
            NONE,UP,DOWN,LEFT,RIGHT
        };

    }
    namespace SCREEN{
        //int ScreenfFlags = SDL_WINDOW_BORDERLESS;
        constexpr float CAMERA_FOLLOW_SPEED = 2;
        constexpr float CAMERA_LERP_SPEED = 0.125f;

        constexpr unsigned char RESIZE = 2;

        constexpr unsigned short HEIGHT = 1024;
        constexpr unsigned short WIDTH = 768;
        constexpr unsigned char CELL_SIZE = 30;
        constexpr unsigned short BORDER_SIZE = 20;

        constexpr unsigned short BOX_PADDING = 20;
        enum FONT_SIZE{
            SMALL = 50,
            MEDIUM = 150,
            LARGE = 200
        };

//        SDL_Color KPRIMARY_COLOR = { 0, 0, 0, 255 };
//        SDL_Color KSECONDARY_COLOR = { 255, 255, 255, 255 };

        //constexpr std::chrono::microseconds FRAME_DURATION(16667);
    }
    namespace MATH{
        struct Vector2D
        {
            Vector2D()
            :x(0.0f), y(0.0f){}
            Vector2D(float _x, float _y)
            :x(_x), y(_y){}
            explicit Vector2D(GLOBAL::GAME::Direction direction)
            {
                switch (direction) {
                    case GLOBAL::GAME::Direction::RIGHT:
                        x = 1;
                        y = 0;
                        break;
                    case GLOBAL::GAME::Direction::LEFT:
                        x = -1;
                        y = 0;
                        break;
                    case GLOBAL::GAME::Direction::UP:
                        x = 0;
                        y = -1;
                        break;
                    case GLOBAL::GAME::Direction::DOWN:
                        x = 0;
                        y = 1;
                        break;
                    case GLOBAL::GAME::Direction::NONE:
                        x = 0;
                        y = 0;
                        break;
                }

            }

            float x, y;

            Vector2D& Add(const Vector2D& vec)
            {this->x += vec.x;this->y += vec.y;return *this;}
            Vector2D& Subtract(const Vector2D& vec)
            {this->x -= vec.x;this->y -= vec.y;return *this;}
            Vector2D& Multiply(const Vector2D& vec)
            {this->x *= vec.x;this->y *= vec.y;return *this;}
            Vector2D& Divide(const Vector2D& vec)
            {this->x /= vec.x;this->y /= vec.y;return *this;}


            friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2){   return  v1.Multiply(v2);    }
            friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2){   return  v1.Subtract(v2);    }
            friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2){   return  v1.Add(v2); }
            friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2){   return  v1.Divide(v2);  }

            Vector2D& operator+=(const Vector2D& vec){   return this->Add(vec);  }
            Vector2D& operator-=(const Vector2D& vec){   return this->Subtract(vec); }
            Vector2D& operator*=(const Vector2D& vec){   return this->Multiply(vec); }
            Vector2D& operator/=(const Vector2D& vec){   return this->Divide(vec);   }
            Vector2D& operator*=(float i){  *this = *this * i ;return *this;}

            Vector2D& operator*(const float& i){this->x *= i; this->y *= i; return *this;}

            Vector2D& operator*(const int& i){this->x *= i; this->y *= i; return *this;}
            Vector2D& Zero(){ this->x = 0; this->y = 0; return *this;}

            friend std::ostream& operator<<(std::ostream& stream, Vector2D vec){   stream << "(" << vec.x << "x"<< "," << vec.y << "y" << ")";   return stream;  }
        };
    }

}