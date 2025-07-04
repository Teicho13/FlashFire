#pragma once
#include <string>
struct SDL_Texture;
struct SDL_FRect;
struct SDL_Rect;
namespace FF
{
    class textureManager
    {
    public:
        static SDL_Texture* CreateTexture(const std::string& texturePath);
        static SDL_Texture* CreateTexture(const std::string& texturePath, int& imageWidth, int& imageHeight);
        static void DeleteTexture(SDL_Texture* texture);

        static void RenderTexture(SDL_Texture* texture, const SDL_FRect* position);
        static void RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_FRect* position);

        static void RenderTexture(SDL_Texture* texture, const SDL_Rect* position);
        static void RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_Rect* position);
    };  
}


