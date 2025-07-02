#include "game.h"
#include <SDL.h>
#include "graphics/window.h"
#include "graphics/renderer.h"

namespace FF
{
	int game::Run()
	{
		if (!Init())
		{
			return -1;
		}

		while (true)
		{
			Render();
		}

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
		renderer::Clear();

		renderer::Present();
	}
}