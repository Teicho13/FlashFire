#pragma once
#include <memory>
#include "core/graphics/sprite.h"

namespace FF
{
    enum class mode : std::uint8_t { chase, scatter, eaten, frightened };
    class ghost
    {
    public:
        void Initialize(const std::string& spritePath, int columns, int rows);
        void Draw() const;
    private:
        int m_Size = 32;
        SDL_FPoint m_Position {368.f,464.f};
        std::unique_ptr<sprite> m_Sprite = nullptr;
        mode m_CurrentMode = mode::chase;
    }; 
}

