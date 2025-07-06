#include "animatedSprite.h"

#include "core/managers/textureManager.h"

namespace FF
{
    animatedSprite::animatedSprite(const std::string& texturePath, int columns, int rows, bool looping, bool startOnPlay)
        :sprite(texturePath, columns, rows)
    {
        m_Animation.Initialize(m_Frames);
        m_Animation.SetFrameSpeed(8);
        m_Animation.SetLooped(looping);
        m_Animation.ResetAnimation();
        if (startOnPlay)
        {
            m_Animation.Play();
        }
    }
    
    void animatedSprite::Update(float deltaTime)
    {
        m_Animation.Update(deltaTime);
        SetFrame(m_Animation.GetCurrentFrame() + m_AnimationOffeset);
    }

    void animatedSprite::SetAnimationOffset(int val)
    {
        m_AnimationOffeset = val;
    }

    animation* animatedSprite::getAnimation()
    {
        return &m_Animation;
    }
}
