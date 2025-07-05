#pragma once
#include <memory>
#include <vector>
#include "core/scene.h"

namespace FF
{
    class sceneManager
    {
    public:
        void Init() const;
        void Update(const float deltaTime) const;
        void Shutdown() const;
        void Render() const;

        void MouseButtonUp(uint8_t button) const;

        void ChangeScene(std::unique_ptr<scene> newScene);
        void RemoveScene();

    private:
        std::vector<std::unique_ptr<scene>> m_Scenes;
    };  
}

