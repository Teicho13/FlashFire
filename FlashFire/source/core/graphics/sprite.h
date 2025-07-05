#pragma once
#include <SDL_rect.h>
#include <string>

struct SDL_Texture;
namespace FF
{
    class sprite
    {
    public:
        sprite(const std::string& texturePath);
        sprite(const std::string& texturePath, int width, int height);

        
        const SDL_Texture* GetTexture() const;
        SDL_Point GetSize() const;

    private:
        SDL_Texture* m_Texture = nullptr;
        SDL_Point m_Size = {0,0};
    }; 
}

