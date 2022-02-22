
// STD
#include <string>

// SDL
#include <SDL.h>
#include <stdio.h>

#pragma once

namespace Core {

	// Forward Declaration
	class Window;
	class Scene;


	class Application {
	public:
		Application(Window* bindWindow);
		~Application();

		void Load(Scene* newScene);

		// Updates the scene and window
		void Update();

		// While-loops the Update function until loop is false
		void Mainloop();

	private:
		bool loop;
		Window* window;
		Scene* scene;
	};
}