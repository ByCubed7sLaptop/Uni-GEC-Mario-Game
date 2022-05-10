#pragma once

#include <set>
#include <map>

namespace Core {

	// Forward declaration
	class Window;

	class Input final
	{
	public:
		
		// Disallow creating an instance of this object
		Input() = delete;

		static void Tick();

		// Change a state of a key
		static void KeyChangeState(unsigned int key, int state);

		// - States

		// Is the key currently pressed
		static bool KeyDown(unsigned int key);

		// Was the key pressed ON THIS FRAME
		static bool OnKeyDown(unsigned int key);

		// Is the key currently released
		static bool KeyUp(unsigned int key);

		// Was the key released ON THIS FRAME
		static bool OnKeyUp(unsigned int key);

	private:

		// Keyboard state.
		static std::map<unsigned int, int> keyboardState;
		static std::set<unsigned int> keyboardChanges;


		// SDL_JoyButtonEvent
		// SDL_MouseMotionEvent
		// SDL_KeyEvent
	};

}