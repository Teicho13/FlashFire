#pragma once
#include <SDL_pixels.h>

namespace FF
{
    class debugLines
    {
    public:
        static void Plot(const float posX, const float posY, const SDL_Color& color);
        static void DrawBox(const float posX, const float posY, const float width, const float height);
        static void DrawBox(const float posX, const float posY, const float width, const float height, const SDL_Color& color);
        static void DrawBoxFill(const float posX, const float posY, const float width, const float height);
        static void DrawBoxFill(const float posX, const float posY, const float width, const float height,const SDL_Color& color);
        static void DrawLine(const float posX, const float posY, const float posX2, const float posY2);
        static void DrawLine(const float posX, const float posY, const float posX2, const float posY2, const SDL_Color& color);
    }; 
}

