#pragma once
#include <memory>
#include <string>
#include "core/graphics/sprite.h"

namespace FF
{
    class entity
    {
    public:
        virtual ~entity() = default;
        
        virtual void Initialize(const std::string& texturePath, int columns, int rows);
        virtual void Draw();
        virtual void Update(float deltaTime){}

        void SetPosition(int newX, int newY);
        
        sprite* GetSprite() const;
        SDL_FPoint GetPosition() const;
    
    protected:

        SDL_FPoint m_Position {48.f,48.f};
        int m_Size = 32;
        
        std::unique_ptr<sprite> m_Sprite = nullptr;    
    }; 
}

