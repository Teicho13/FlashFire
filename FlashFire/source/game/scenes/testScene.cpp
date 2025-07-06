#include "testScene.h"
#include "core/managers/textureManager.h"
#include "game/entities/player.h"
#include "utility/debugLines.h"
#include "utility/logger.h"

namespace FF
{
    player pacman;
    
    void testScene::Init()
    {
        testTexture = textureManager::CreateTexture(std::string("assets/images/temp/boomkin.jpg"));
        pacman.Initialize();
    }

    void testScene::Tick(const float deltaTime)
    {
        pacman.Update(deltaTime);
    }

    void testScene::ShutDown()
    {
    }

    void testScene::Render()
    {
        debugLines::DrawBox(30,30,30,30);
        debugLines::DrawBoxFill(90,30,30,30);
        debugLines::Plot(50,80,SDL_Color{255,255,255,255});
        debugLines::DrawLine(10,10,10,60,SDL_Color{255,0,255,255});

        /*constexpr SDL_FRect tempRec{ 150, 150, 150, 150};
        textureManager::RenderTexture(testTexture,&tempRec);*/

        pacman.Draw();
    }

    void testScene::MouseButtonUp(const uint8_t button)
    {
        Log::Info("Mouse Button: {} Up", button);
    }
}
