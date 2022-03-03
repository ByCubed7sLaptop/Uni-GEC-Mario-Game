#pragma once

#include <set>

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
		void KeyChangeState(int key, int state);

		// - States

		// Is the key currently pressed
		bool KeyDown(int key);

		// Was the key pressed ON THIS FRAME
		bool OnKeyDown(int key);

		// Is the key currently released
		bool KeyUp(int key);

		// Was the key released ON THIS FRAME
		bool OnKeyUp(int key);

	private:
		// Keyboard state.
		int keyboard[1024];
		std::set<int> keyboardChanges;


		// SDL_JoyButtonEvent
		// SDL_MouseMotionEvent
		// SDL_KeyEvent
	};

}