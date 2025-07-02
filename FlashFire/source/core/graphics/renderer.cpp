#include "renderer.h"
#include "window.h"
#include "utility/logger.h"
namespace FF
{
	bool renderer::Create()
	{
		Log::Info("Creating Renderer");

		//Create renderer for SDL and set default background color
		g_Renderer = SDL_CreateRenderer(window::GetWindow(), -1, 0);

		if (g_Renderer == nullptr)
		{
			Log::Error("Failed to create renderer");
			return false;
		}

		SDL_SetRenderDrawColor(g_Renderer, 27, 146, 214, 255);

		return true;
	}

	void renderer::Destroy()
	{
		Log::Info("Destroying Renderer");

		SDL_DestroyRenderer(g_Renderer);
	}

	void renderer::Clear()
	{
		//Clear render screen for new frame
		//SDL_SetRenderDrawColor(g_Renderer, 27, 146, 214, 255);
		SDL_SetRenderDrawColor(g_Renderer, 0, 0, 0, 255);
		SDL_RenderClear(g_Renderer);
	}

	void renderer::Present()
	{
		//Render everything to the screen
		SDL_RenderPresent(g_Renderer);
	}

	SDL_Renderer* renderer::GetRenderer()
	{
		return g_Renderer;
	}

}