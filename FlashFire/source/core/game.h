#pragma once
#include <SDL_stdinc.h>

#include "managers/sceneManager.h"
#include "utility/deltaTime.h"

namespace FF
{
	class game
	{
	public:

		int Run();
		
	private:

		bool Init();
		bool Shutdown();
		void Render() const;
		void HandleInputEvents();
		
		const Uint8* m_KeyStates = nullptr;
		bool m_ShouldRun = false;
		DeltaTime m_DeltaTime;
		sceneManager m_SceneManager;
	};
}


