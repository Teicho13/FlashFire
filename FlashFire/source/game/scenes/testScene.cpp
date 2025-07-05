#include "testScene.h"
#include "core/managers/textureManager.h"
#include "utility/debugLines.h"
#include "utility/logger.h"

namespace FF
{
    void testScene::Init()
    {
        testTexture = textureManager::CreateTexture(std::string("assets/images/temp/boomkin.jpg"));
    }

    void testScene::Tick(const float deltaTime)
    {
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

        constexpr SDL_FRect tempRec{ 150, 150, 150, 150};
        textureManager::RenderTexture(testTexture,&tempRec);
    }

    void testScene::MouseButtonUp(const uint8_t button)
    {
        Log::Info("Mouse Button: {} Up", button);
    }
}
