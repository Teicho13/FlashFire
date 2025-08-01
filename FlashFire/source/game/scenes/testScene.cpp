#include "testScene.h"
#include "core/managers/textureManager.h"
#include "game/map.h"
#include "game/entities/player.h"
#include "utility/logger.h"

namespace FF
{
    void testScene::Init()
    {
        testTexture = textureManager::CreateTexture(std::string("assets/images/temp/boomkin.jpg"));
        m_Player.Initialize();
        m_blinky.Initialize(std::string("assets/images/characters/blinky.png"),5,1);
        m_blinky.SetPosition(368.f,464.f);
        m_Map.SetTileMap(std::string("assets/maps/pacman-mapsheet.png"),std::string("assets/maps/FlashFireTilemap.csv"),16,3);
        m_Player.m_MapPointer = &m_Map;
    }

    void testScene::Tick(const float deltaTime)
    {
        m_Player.Update(deltaTime);
        m_Map.PlayerPickupsCheck(m_Player);
    }
    
    void testScene::Render()
    {
        m_Map.DrawMap();
        m_Player.Draw();
        m_blinky.Draw();
    }

    void testScene::MouseButtonUp(const uint8_t button)
    {
        Log::Info("Mouse Button: {} Up", button);
    }

    void testScene::KeyDown(int32_t button)
    {
       m_Player.SetDirection(button); 
    }
}
