#pragma once
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
		
		const uint8_t* m_KeyStates = nullptr;
		bool m_ShouldRun = false;
		DeltaTime m_DeltaTime;
		sceneManager m_SceneManager;
	};
}


