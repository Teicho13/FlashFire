#pragma once
#include "entity.h"
#include "core/graphics/animatedSprite.h"

namespace FF
{
   class map;
   class player : public entity
   {
   public:

      void Initialize(const std::string& texturePath, int columns, int rows) override;
      void Update(float deltaTime) override;
      void Move(float deltaTime);
      void Draw() override;

      void NextDirection(float deltaTime);
      void SetDirection(int32_t direction);
      bool NextTileIsWalkable() const;

      map* m_MapPointer = nullptr;
      
   private:
      direction m_Direction = direction::none;
      direction m_NextDirection = direction::none;

      animatedSprite* m_AnimatedSprite = nullptr;
   };

}


