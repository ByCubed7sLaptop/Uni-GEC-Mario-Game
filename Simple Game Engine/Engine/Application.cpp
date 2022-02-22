#include "Application.h"

#include "SDLWindow.h"

namespace Core {

	Application::Application(SDLW::SDLWindow* bindWindow)
	{
		scene = nullptr;
		window = bindWindow;
		loop = true;
	}

	Application::~Application()
	{
		if (window != nullptr) {
			delete window;
			window = nullptr;
		}
	}

	void Application::Load(Scene* newScene)
	{
		// Unload the scene, ect

		scene = newScene;

		// Load the new scene
	}

	void Application::Update()
	{
		// Update the scene
		
		// Draw the scene

		// Update the window
		window->Update();

		// Wait till next frame
		//SDL_Delay(20);
	}

	void Application::Mainloop()
	{
		while (true) {
			Update();

			// Should we exit?
			if (!loop) break;
		}
	}
}