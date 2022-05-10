#include "Application.h"

#include "SDLWindow.h"
#include "Component.h"
#include "Scene.h"

namespace Core {

	Application* Application::instance = nullptr;

	Application::Application(std::string name)
	{
		window = new SDLW::Window(name);
		scene = nullptr;
		loop = true;

		Application::instance = this;
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

		window->SetBackgroundColour({ 0, 0, 0 });

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
		SDL_Renderer* renderer = window->Renderer();

		Uint32 frameCurrent = 0;
		Uint32 frameLast = 0;

		Uint32 frameDelay = 1;
		bool loop = true;
		while (loop)
		{
			frameCurrent = SDL_GetTicks();
			Uint32 deltaTime = frameCurrent - frameLast;

			// Reset the render draw color
			SDL_RenderClear(renderer);


			// Update the window, poll events, ect
			loop = window->Update();

			if (scene != nullptr) {
				scene->Update(deltaTime);

				// Render the Components
				for (Component* component : scene->components)
					component->Draw(renderer);
			}

			// Swap the buffer
			SDL_RenderPresent(renderer);


			frameLast = frameCurrent;
			if (frameDelay > deltaTime) SDL_Delay(frameDelay - deltaTime);
		}

	}
	SDLW::Window* Application::Window()
	{
		return window;
	}
}