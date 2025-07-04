#pragma once
#include <string>
#include <unordered_map>

struct SDL_Surface;
struct SDL_Texture;
namespace FF
{
    class resourceManager
    {
    public:
        SDL_Surface* GetSurface(const std::string& filePath);
        SDL_Texture* GetTexture(const std::string& filePath);

        static resourceManager* GetResourceManager();

    private:
        std::unordered_map<std::string, SDL_Surface*> m_Surfaces;
        std::unordered_map<std::string, SDL_Texture*> m_Textures;
    };  
}

