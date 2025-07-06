#include "sceneManager.h"
#include "utility/logger.h"


namespace FF
{
    void sceneManager::Init() const
    {
        if (!m_Scenes.empty())
        {
            m_Scenes.back()->Init();
        }
        else
        {
            Log::Warning("No scene found to Init");
        }
    }

    void sceneManager::Update(const float deltaTime) const
    {
        if(!m_Scenes.empty())
        {
            m_Scenes.back()->Tick(deltaTime);
        }
    }

    void sceneManager::Shutdown() const
    {
        if(!m_Scenes.empty())
        {
            m_Scenes.back()->ShutDown();
        }
    }

    void sceneManager::Render() const
    {
        if(!m_Scenes.empty())
        {
            m_Scenes.back()->Render();
        }
    }

    void sceneManager::MouseButtonUp(const uint8_t button) const
    {
        if (!m_Scenes.empty())
        {
            m_Scenes.back()->MouseButtonUp(button);
        }
    }

    void sceneManager::KeyDown(const int32_t button) const
    {
        if (!m_Scenes.empty())
        {
            m_Scenes.back()->KeyDown(button);
        }
    }

    void sceneManager::KeyUp(const int32_t button) const
    {
        if (!m_Scenes.empty())
        {
            m_Scenes.back()->KeyUp(button);
        }
    }

    void sceneManager::ChangeScene(std::unique_ptr<scene> newScene)
    {
        if(newScene != nullptr)
        {
            //We first remove the current scene if it exists.
            RemoveScene();
            
            m_Scenes.push_back(std::move(newScene));
            m_Scenes.back()->Init();
        }
        else
        {
            Log::Warning("Invalid scene passed");
            return;
        }
    }

    //Removes last scene (LIFO)
    void sceneManager::RemoveScene()
    {
        //Remove current state
        if (!m_Scenes.empty())
        {
            //call Shutdown for current state before removal to clean up.
            m_Scenes.back()->ShutDown();
            m_Scenes.pop_back();
        }
    }
}
