#include "player.h"
#include "game/map.h"
#include "gameConfig.h"
#include "utility/debugLines.h"

namespace FF
{
    void player::Initialize(const std::string& texturePath, int columns, int rows)
    {
        auto newSprite = std::make_unique<animatedSprite>(texturePath,columns,rows,true,true);
        newSprite->getAnimation()->SetMaxFrames(2);
        newSprite->SetAnimationOffset(0);
        
        m_AnimatedSprite = newSprite.get();
        m_Sprite = std::move(newSprite);
    }

    void player::Update(const float deltaTime)
    {
        entity::Update(deltaTime);

        if (m_AnimatedSprite)  m_AnimatedSprite->Update(deltaTime);
        NextDirection(deltaTime);
        if (NextTileIsWalkable())
        {
            Move(deltaTime);  
            Move(deltaTime);  
        }
    }

        void player::Move(float deltaTime)
    {
        switch (m_Direction)
        {
        case direction::up:
            m_Position.y -= (m_Speed * deltaTime);
            break;
        case direction::down:
            m_Position.y += (m_Speed * deltaTime);
            break;
        case direction::left:
            m_Position.x -= (m_Speed * deltaTime);
            break;
        case direction::right:
            m_Position.x += (m_Speed * deltaTime);
            break;
        case direction::none:
            break;
        }
        
        //Logic for teleporting between 2 sides
        
        if (m_Position.x <= -32.f)
        {
            m_Position.x = 864.f;
            return;
        }

        if (m_Position.x >= 900.f)
        {
            m_Position.x = 0.f;
            return;
        }
    }

        void player::Draw()
        {
            entity::Draw();

            debugLines::DrawBox(static_cast<int>(m_Position.x / 32) * 32.f,static_cast<int>(m_Position.y / 32) * 32.f,32.f,32.f);
            debugLines::DrawBox((static_cast<int>((m_Position.x - 8) / 32) - 1) * 32.f,static_cast<int>(m_Position.y / 32) * 32.f,32.f,32.f,SDL_Color{255,255,0,255});
            debugLines::DrawBox((static_cast<int>((m_Position.x + 8) / 32) + 1) * 32.f,static_cast<int>(m_Position.y / 32) * 32.f,32.f,32.f,SDL_Color{255,0,255,255});
        }

        void player::NextDirection(const float deltaTime)
    {
        if (m_Direction == m_NextDirection) return;
        direction oldDirection = m_Direction;
        m_Direction = m_NextDirection;
        //Check if the new direction can we walked towards otherwise we revert the direction change.
        if (!NextTileIsWalkable())
        {
            m_Direction = oldDirection;
            return;
        }

        if (GameConfig::TurnSnapping)
        {
            if (m_Direction == direction::left ||  m_Direction == direction::right)
            {
                m_Position.y = (static_cast<int>( m_Position.y / 32) * 32.f) + 16.f;
                return;
            }

            if (m_Direction == direction::up ||  m_Direction == direction::down)
            {
                m_Position.x = (static_cast<int>( m_Position.x / 32) * 32.f) + 16.f;
                return;
            } 
        }
    }

    void player::SetDirection(const int32_t direction)
    {
        switch (direction)
        {
        default:
        case 100:
            m_NextDirection = direction::right;
            m_AnimatedSprite->SetAnimationOffset(0);
            break;

        case 97:
            m_NextDirection = direction::left;
            m_AnimatedSprite->SetAnimationOffset(3);
            break;

        case 115:
            m_NextDirection = direction::down;
            m_AnimatedSprite->SetAnimationOffset(6);
            break;

        case 119:
            m_NextDirection = direction::up;
            m_AnimatedSprite->SetAnimationOffset(9);
            break;
        }
    }

    bool player::NextTileIsWalkable() const
    {
        if (!m_MapPointer) return false;
        
        int NextTileID = 0;
        switch (m_Direction) {
        case direction::up:
            NextTileID = m_MapPointer->GetTileData(static_cast<int>(m_Position.x  / 32) ,static_cast<int>((m_Position.y + 12) / 32) - 1);
            break;
        case direction::down:
            NextTileID = m_MapPointer->GetTileData(static_cast<int>(m_Position.x  / 32) ,static_cast<int>((m_Position.y - 16) / 32) + 1);
            break;
        case direction::left:
            NextTileID = m_MapPointer->GetTileData(static_cast<int>((m_Position.x + 12) / 32) - 1,static_cast<int>(m_Position.y / 32.f));
            break;
        case direction::right:
            NextTileID = m_MapPointer->GetTileData(static_cast<int>((m_Position.x - 16) / 32) + 1,static_cast<int>(m_Position.y / 32.f));
            break;
        case direction::none:
            return false;
        }

        return map::IsTileWalkable(NextTileID);
    }
}
