#pragma once
#include "game/entities/entity.h"

namespace FF
{
    enum class mode : std::uint8_t { chase, scatter, eaten, frightened };
    class ghost : public entity
    {
    public:
        mode GetActiveMode() const;
    private:
        mode m_CurrentMode = mode::chase;
    };
}

