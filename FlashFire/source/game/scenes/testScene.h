#pragma once
#include <SDL_render.h>
#include "core/scene.h"
#include "game/map.h"
#include "game/entities/player.h"
#include "game/entities/ghosts/ghost.h"

namespace FF
{
    class testScene : public scene
    {
    public:
        void Init() override;
        void Tick(const float deltaTime) override;
        void ShutDown() override {}
        void Render() override;
        void MouseButtonUp(const uint8_t button) override;
        void KeyDown(int32_t button) override;
        void KeyUp(int32_t button) override {}

    private:
        SDL_Texture* testTexture = nullptr;

        player m_Player;
        ghost m_blinky;
        map m_Map;
    };   
}

