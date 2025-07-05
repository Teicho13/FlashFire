#pragma once
#include <SDL_render.h>
#include "core/scene.h"

namespace FF
{
    class testScene : public scene
    {
    public:
        void Init() override;
        void Tick(const float deltaTime) override;
        void ShutDown() override;
        void Render() override;
        void MouseButtonUp(const uint8_t button) override;

    private:
        SDL_Texture* testTexture = nullptr;
    };   
}

