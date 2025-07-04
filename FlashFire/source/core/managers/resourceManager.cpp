#include "resourceManager.h"

#include <assert.h>
#include <SDL_surface.h>
#include <SDL_render.h>
#include <SDL_image.h>

#include "core/graphics/renderer.h"

namespace FF
{
    static resourceManager* s_ResourceManager = nullptr;

    void resourceManager::Create()
    {
        s_ResourceManager = new resourceManager();
    }

    void resourceManager::Destroy()
    {
        delete s_ResourceManager;
        s_ResourceManager = nullptr;
    }

    SDL_Surface* resourceManager::GetSurface(const std::string& filePath)
    {
        //Look for surface
        auto search = m_Surfaces.find(filePath);
        if (search != m_Surfaces.end())
        {
            //Return existing surface
            return m_Surfaces[filePath];
        }

        //Create new Surface and add to the list
        SDL_Surface* surface = IMG_Load(filePath.c_str());
        m_Surfaces.insert(std::make_pair(filePath, surface));
        return m_Surfaces[filePath];
    }

    SDL_Texture* resourceManager::GetTexture(const std::string& filePath)
    {
        //look for texture
        auto search = m_Textures.find(filePath);
        if (search != m_Textures.end())
        {
            //return existing texture
            return m_Textures[filePath];
        }

        //Create new texture from surface, first look for surface otherwise we create that first.
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer::GetRenderer(), GetSurface(filePath));
        m_Textures.insert(std::make_pair(filePath, texture));
        return m_Textures[filePath];
    }

    resourceManager* resourceManager::GetResourceManager()
    {
        assert(s_ResourceManager);
        return s_ResourceManager;
    }
}
