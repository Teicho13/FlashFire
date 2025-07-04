#include "textureManager.h"
#include "resourceManager.h"
#include "core/graphics/renderer.h"
#include <SDL_render.h>

namespace FF
{
    SDL_Texture* textureManager::CreateTexture(const std::string& texturePath)
    {
        //Create texture
        SDL_Texture* TempTexture = resourceManager::GetResourceManager()->GetTexture(texturePath);

        return TempTexture;
    }

    SDL_Texture* textureManager::CreateTexture(const std::string& texturePath, int& imageWidth, int& imageHeight)
    {

        //Create texture
        SDL_Surface* Surface = resourceManager::GetResourceManager()->GetSurface(texturePath);
        SDL_Texture* TempTexture = resourceManager::GetResourceManager()->GetTexture(texturePath);


        imageWidth = Surface->w;
        imageHeight = Surface->h;
        //Free Surface since we don't need it anymore
        SDL_FreeSurface(Surface);
        return TempTexture;
    }

    void textureManager::DeleteTexture(SDL_Texture* texture)
    {
        SDL_DestroyTexture(texture);
    }

    void textureManager::RenderTexture(SDL_Texture* texture, const SDL_FRect* position)
    {
        SDL_RenderCopyF(renderer::GetRenderer(), texture, nullptr, position);
    }

    void textureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_FRect* position)
    {
        SDL_RenderCopyF(renderer::GetRenderer(), texture, sourcePos, position);
    }

    void textureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* position)
    {
        SDL_RenderCopy(renderer::GetRenderer(), texture, NULL, position);
    }

    void textureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_Rect* position)
    {
        SDL_RenderCopy(renderer::GetRenderer(), texture, sourcePos, position);
    }
}
