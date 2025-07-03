#pragma once
#include <SDL_video.h>
namespace FF
{
	class window
	{
		public:

			static bool Create();
			static void Destroy();

			static SDL_Window* GetWindow();
	};
}


