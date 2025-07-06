#include "game.h"
#include <SDL.h>

#include "graphics/window.h"
#include "graphics/renderer.h"
#include "managers/resourceManager.h"
#include "game/scenes/testScene.h"
#include "utility/logger.h"

namespace FF
{
	int game::Run()
	{
		//Initialize project
		if (!Init())
		{
			return -1;
		}

		//Update project
		while (m_ShouldRun)
		{
			m_DeltaTime.Update();
			HandleInputEvents();
			//If we are supposed to stop, exit out early.
			if (!m_ShouldRun) break;
			m_SceneManager.Update(m_DeltaTime.GetSeconds());
			Render();
		}

		//Shutdown project
		Shutdown();

		return 0;
	}
	
	bool game::Init()
	{
		//Initialize SDL
		if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		{
			return false;
		}

		//Set current time for DeltaTime
		m_DeltaTime.GetTime();

		//Create Window
		if (!window::Create())
		{
			return false;
		}

		//create renderer
		if (!renderer::Create())
		{
			return false;
		}

		resourceManager::Create();

		//save pointer to data of all keystates
		m_KeyStates = SDL_GetKeyboardState(nullptr);
		m_ShouldRun = true;

		//Create a test scene that we start in
		m_SceneManager.ChangeScene(std::make_unique<testScene>());
		
		return true;
	}

	bool game::Shutdown()
	{
		resourceManager::Destroy();
		renderer::Destroy();
		window::Destroy();
		SDL_Quit();
		return true;
	}
	
	void game::Render() const
	{
		if (!m_ShouldRun) return;
		
		renderer::Clear();
		//Render all objects in current scene.
		m_SceneManager.Render();
		renderer::Present();
	}

	void game::HandleInputEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				//Window "X" is clicked
			case SDL_QUIT:
				m_ShouldRun = false;
				break;

				//key is pressed
			case SDL_KEYDOWN:
				//If Escape is clicked exit out
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					m_ShouldRun = false;
					return;
				}

				m_SceneManager.KeyDown(event.key.keysym.sym);
				break;

			case SDL_MOUSEBUTTONUP:
				m_SceneManager.MouseButtonUp(event.button.button);
				break;
			}
		}
	}
}
