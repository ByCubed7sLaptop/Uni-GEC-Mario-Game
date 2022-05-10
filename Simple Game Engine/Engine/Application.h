#pragma once

# include "Vector.h"

// STD
#include <string>

// SDL
#include <SDL.h>
#include <stdio.h>

#pragma once

// Forward Declaration
namespace SDLW { class Window; }

namespace Core {

	// Forward Declaration
	class Scene;


	class Application {
	public:
		Application(std::string name);
		~Application();

		void Load(Scene* newScene);

		// Updates the scene and window
		void Update();

		// While-loops the Update function until loop is false
		void Mainloop();

		SDLW::Window* Window();

		// TODO: Consider transfering into a static class
		static Application* instance;

	private:
		bool loop;
		SDLW::Window* window;
		Scene* scene;

	};
}