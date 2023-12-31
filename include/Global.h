#pragma once
#include <SDL.h>
#include "SDL_ttf.h"
#include "SDL_mixer.h"
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

        enum InteractionStatus{
            NORMAL = 0,
            HOVER = 1,
            PRESSED = 2
        };

        struct Scene
        {
            Scene() = default;
            virtual void OnEnter(){}
            virtual void OnExit(){}
            virtual void Draw(){}
            virtual void Update(){}
            virtual void Init(){}
            virtual void Refresh(){}
            bool isInitialized;
        };
    }
    namespace SCREEN{
        constexpr float CAMERA_FOLLOW_SPEED = 2;
        constexpr float CAMERA_LERP_SPEED = 0.125f;

        constexpr unsigned char RESIZE = 2;

        constexpr unsigned short SCREEN_HEIGHT = 1024;
        constexpr unsigned short SCREEN_WIDTH = 768;


        constexpr unsigned char CELL_SIZE = 48;
        constexpr unsigned short BORDER_SIZE = 20;

        constexpr unsigned short BOX_PADDING = 20;
        enum FONT_SIZE{
            TINY = 25,
            SMALL = 50,
            MEDIUM = 150,
            LARGE = 200
        };
    }
    namespace UI{
        enum ButtonSize{
            Tiny,
            Small,
            Medium,
            Large
        };
        struct ButtonData{
            ButtonData(int x, int y, GLOBAL::UI::ButtonSize size)
            :XPosition(x),YPosition(y),Size(size){}
            int XPosition, YPosition;
            ButtonSize Size;
        };
        struct TextButtonData{
            TextButtonData(int x, int y, ButtonSize size, const char* text, GLOBAL::SCREEN::FONT_SIZE fontSize, int eventCode, const char* soundClipPath)
            :XPosition(x),YPosition(y),Size(size),Text(text),FontSize(fontSize),EventCode(eventCode),SoundClipPath(soundClipPath){}
            int XPosition, YPosition;
            ButtonSize Size;
            const char* Text;
            SCREEN::FONT_SIZE FontSize;
            int EventCode;
            const char* SoundClipPath;
        };
        struct TextData{
            TextData(int x, int y, const char* text, GLOBAL::SCREEN::FONT_SIZE fontSize)
            :XPosition(x), YPosition(y), Text(text), FontSize(fontSize){}
            int XPosition, YPosition;
            const char* Text;
            SCREEN::FONT_SIZE FontSize;
        };
    }
    namespace AUDIO{
        struct Sound{
            const char* filePath;
        };

    }
    namespace MATH{
        struct Vector2D
        {
            Vector2D()
            :x(0.0f), y(0.0f){}
            Vector2D(int _x, int _y)
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
            int x, y;
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
            bool operator==(Vector2D& vec){ return (x == vec.x) && (y == vec.y);   }
            Vector2D& operator*=(int i){  *this = *this * i ;return *this;}
            Vector2D& operator*(const float& i){this->x *= i; this->y *= i; return *this;}
            Vector2D& operator*(const int& i){this->x *= i; this->y *= i; return *this;}
            Vector2D& operator/(const int& i){this->x /= i; this->y /= i; return *this;}
            Vector2D& Zero(){ this->x = 0; this->y = 0; return *this;}
            friend std::ostream& operator<<(std::ostream& stream, Vector2D vec){   stream << "(" << vec.x << "x"<< "," << vec.y << "y" << ")";   return stream;  }
        };
    }

}