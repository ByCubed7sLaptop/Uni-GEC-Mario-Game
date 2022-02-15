
// STD
#include <string>

// SDL
#include <SDL.h>
#include <stdio.h>

#pragma once

namespace Core {
	class Application {
	public:
		Application();
		~Application();

		void Mainloop();

	private:
		bool loop;
	};
}