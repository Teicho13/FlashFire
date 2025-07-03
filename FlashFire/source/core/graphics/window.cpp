#include "window.h"
#include "gameConfig.h"
#include "utility/logger.h"
#include "renderer.h"


namespace FF 
{
	static  SDL_Window* s_Window = nullptr;
	bool window::Create()
	{
		Log::Info("Creating Window");

		auto windowFlag = (GameConfig::Fullscreen) ? SDL_WINDOW_FULLSCREEN : (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		s_Window = SDL_CreateWindow("Cascade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GameConfig::Width, GameConfig::Height, windowFlag);

		if (s_Window == nullptr)
		{
			Log::Error("Failed to create window");
			return false;
		}

		return true;
	}

	void window::Destroy()
	{
		Log::Info("Destroying Window");

		SDL_DestroyWindow(s_Window);
	}

	SDL_Window* window::GetWindow()
	{
		assert(s_Window);
		return s_Window;
	}
}