#include "game.h"
#include <SDL.h>
#include "graphics/window.h"
#include "graphics/renderer.h"
#include "managers/resourceManager.h"
#include "managers/textureManager.h"
#include "utility/debugLines.h"

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
			
			Render();
		}

		//Shutdown project
		Shutdown();

		return 0;
	}

	SDL_Texture* testTexture;
	
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

		testTexture = textureManager::CreateTexture(std::string("assets/images/temp/boomkin.jpg"));
		
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
	
	void game::Render()
	{
		if (!m_ShouldRun) return;
		
		renderer::Clear();
		//note: Render objects here in between clear and presenting to screen

		debugLines::DrawBox(30,30,30,30);
		debugLines::DrawBoxFill(90,30,30,30);
		debugLines::Plot(50,80,SDL_Color{255,255,255,255});
		debugLines::DrawLine(10,10,10,60,SDL_Color{255,0,255,255});

		const SDL_FRect tempRec{ 150, 150, 150, 150};
		textureManager::RenderTexture(testTexture,&tempRec);
		
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
