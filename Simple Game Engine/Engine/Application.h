
// STD
#include <string>

// SDL
#include <SDL.h>
#include <stdio.h>

#pragma once

// Forward Declaration
namespace SDLW { class SDLWindow; }

namespace Core {

	// Forward Declaration
	class Scene;


	class Application {
	public:
		Application(SDLW::SDLWindow* bindWindow);
		~Application();

		void Load(Scene* newScene);

		// Updates the scene and window
		void Update();

		// While-loops the Update function until loop is false
		void Mainloop();

	private:
		bool loop;
		SDLW::SDLWindow* window;
		Scene* scene;
	};
}