#include "player.h"
#include "core/managers/textureManager.h"

namespace FF
{
    void player::Initialize()
    {
        m_Sprite.reset(new sprite("assets/images/characters/pacman.png",12,1)); 
    }

    sprite* player::GetSprite() const
    {
        return m_Sprite.get();
    }

    void player::Draw()
    {
        if (m_Sprite)
        {
            SDL_Rect sourceRec{32,0,32,32};
            constexpr SDL_FRect tempRec{ 150, 150, 32, 32};
            m_Sprite->GetSourceRec(sourceRec);
            textureManager::RenderTexture(m_Sprite->GetTexture(),&sourceRec,&tempRec);
        }
    }
}
