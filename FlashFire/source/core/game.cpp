#include "game.h"
#include <SDL.h>
#include "graphics/window.h"
#include "graphics/renderer.h"

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
			HandleInputEvents();
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

		//save pointer to data of all keystates
		m_KeyStates = SDL_GetKeyboardState(nullptr);
		m_ShouldRun = true;
		
		return true;
	}

	bool game::Shutdown()
	{
		renderer::Destroy();
		window::Destroy();
		SDL_Quit();
		return true;
	}
	
	void game::Render()
	{
		if (!m_ShouldRun) return;
		
		renderer::Clear();
		//note: Render objects here in between clear and presenting to screen
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
				break;
			}
		}
	}
}
