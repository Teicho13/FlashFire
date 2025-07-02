#pragma once
#include <sdl_render.h>
namespace FF
{
	class renderer
	{
	public:
		static bool Create();
		static void Destroy();

		static void Clear();
		static void Present();

		static SDL_Renderer* GetRenderer();
	};

	inline SDL_Renderer* g_Renderer = nullptr;
}


