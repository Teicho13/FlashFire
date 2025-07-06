#pragma once
#include "animation.h"
#include "sprite.h"

namespace FF
{
    class animatedSprite : public sprite
    {
    public:
        animatedSprite(const std::string& texturePath, int columns, int rows, bool looping = false, bool startOnPlay = false);
        
        void Update(float deltaTime);
        void SetAnimationOffset(int val);
        
        animation* getAnimation();
        
    private:
        animation m_Animation;
        int m_AnimationOffeset = 0;
    };  
}

