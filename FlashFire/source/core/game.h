#pragma once
#include <SDL_stdinc.h>

namespace FF
{
	class game
	{
	public:

		int Run();
		bool Init();
		bool Shutdown();
		void Render();
		void HandleInputEvents();

		private:
		const Uint8* m_KeyStates = nullptr;
		bool m_ShouldRun = false;
	};
}


