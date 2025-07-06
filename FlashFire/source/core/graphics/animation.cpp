#include "animation.h"

void FF::animation::Initialize(int maxFrame)
{
    if (maxFrame <= 0) { maxFrame = 1;}
    m_MaxFrames = maxFrame;
}

void FF::animation::SetLooped(bool val)
{
    m_LoopAnimation = val;
}

void FF::animation::SetFrameSpeed(float val)
{
    m_FrameSpeed = val;
}

void FF::animation::SetMaxFrames(int val)
{
    m_MaxFrames = val;
}

void FF::animation::Play()
{
    m_IsPlaying = true;
}

void FF::animation::Stop()
{
    m_IsPlaying = false;
}

void FF::animation::ResetAnimation()
{
    m_CurrentFrame = 0;
}

void FF::animation::Update(const float dt)
{
    if(m_IsPlaying)
    {
        m_time += m_FrameSpeed * dt;
        if(m_time >= 1)
        {
            m_CurrentFrame++;
            m_time = 0.f;

            if(m_CurrentFrame > m_MaxFrames)
            {
                if(m_LoopAnimation)
                {
                    m_CurrentFrame = 0;
                }
                else
                {
                    Stop();
                }
            }
        }
    }
}

bool FF::animation::IsLooped() const
{
    return m_LoopAnimation;
}

int FF::animation::GetCurrentFrame() const
{
    return m_CurrentFrame;
}
