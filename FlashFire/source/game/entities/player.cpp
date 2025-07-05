#include "player.h"
#include "core/managers/textureManager.h"

namespace FF
{
    void player::Initialize()
    {
        m_Sprite.reset(new sprite("assets/images/characters/pacman.png")); 
    }

    void player::Draw()
    {
        if (m_Sprite)
        {
            constexpr SDL_Rect sourceRec{32,0,32,32};
            constexpr SDL_FRect tempRec{ 150, 150, 32, 32};
            textureManager::RenderTexture(m_Sprite->GetTexture(),&sourceRec,&tempRec);
        }
    }
}
