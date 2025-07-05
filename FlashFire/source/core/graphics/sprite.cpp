#include "sprite.h"
#include <SDL_render.h>

#include "core/managers/resourceManager.h"

namespace FF
{
    sprite::sprite(const std::string& texturePath)
        : m_Texture(resourceManager::GetResourceManager()->GetTexture(texturePath))
    {
        //Get the width & height of the image from our surface.
        const auto surface = resourceManager::GetResourceManager()->GetSurface(texturePath);
        m_Size.x = surface->w;
        m_Size.y = surface->h;
    }

    sprite::sprite(const std::string& texturePath, int width, int height)
    : m_Texture(resourceManager::GetResourceManager()->GetTexture(texturePath))
    , m_Size {width, height}
    {
    }

    SDL_Texture* sprite::GetTexture() const
    {
        return m_Texture;
    }

    SDL_Point sprite::GetSize() const
    {
        return m_Size;
    }
}
