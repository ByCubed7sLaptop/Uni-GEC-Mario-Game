#include "Application.h"

#include "SDLWindow.h"
#include "Component.h"
#include "Scene.h"

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
		SDL_Renderer* renderer = window->Renderer();

		Uint32 frameCurrent = 0;
		Uint32 frameLast = 0;

		Uint32 frameDelay = 1;
		bool loop = true;
		while (loop)
		{
			frameCurrent = SDL_GetTicks();
			Uint32 deltaTime = frameCurrent - frameLast;

			SDL_RenderClear(renderer);

			// Update the Components
			for (Component* component : scene->components)
				component->Update(deltaTime);
			// https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php

			// Update the window
			loop = window->Update();

			// Render the Components
			for (Component* component : scene->components)
				component->Draw(renderer);

			// Swap the buffer
			SDL_RenderPresent(renderer);


			frameLast = frameCurrent;
			if (frameDelay > deltaTime) SDL_Delay(frameDelay - deltaTime);
		}

		SDL_DestroyRenderer(renderer);

		//Quit SDL subsystems
		SDL_Quit();
	}
}