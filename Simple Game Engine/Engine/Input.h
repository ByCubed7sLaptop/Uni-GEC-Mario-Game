#pragma once

#include <set>
#include <map>

namespace Core {

	// Forward declaration
	class Window;

	class Input
	{
	public:
		static Input* instance;

		Input();
		
		void Tick();

		// Change a state of a key
		void KeyChangeState(unsigned int key, int state);

		// - States

		// Is the key currently pressed
		bool KeyDown(unsigned int key);

		// Was the key pressed ON THIS FRAME
		bool OnKeyDown(unsigned int key);

		// Is the key currently released
		bool KeyUp(unsigned int key);

		// Was the key released ON THIS FRAME
		bool OnKeyUp(unsigned int key);

	private:
		// Keyboard state.
		std::map<unsigned int, int> keyboardState;
		std::set<unsigned int> keyboardChanges;


		// SDL_JoyButtonEvent
		// SDL_MouseMotionEvent
		// SDL_KeyEvent
	};

}