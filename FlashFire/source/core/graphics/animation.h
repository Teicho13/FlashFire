#pragma once

namespace FF
{
    class animation
    {
    public:
        void Initialize(int maxFrame);

        void SetLooped(bool val);
        void SetFrameSpeed(float val);
        void SetMaxFrames(int val);

        void Play();
        void Stop();
        void ResetAnimation();

        void Update(const float dt);

        bool IsLooped() const;
        int GetCurrentFrame() const;

    private:
        bool m_IsPlaying = false;
        bool m_LoopAnimation = true;
	
        float m_FrameSpeed = 1.f;

        int m_CurrentFrame = 0;
        int m_MaxFrames = 0;

        float m_time = 0.0f;
    }; 
}

