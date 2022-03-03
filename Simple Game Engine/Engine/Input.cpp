#include "Input.h"

namespace Core {

	Input* Input::instance = nullptr;

	Input::Input() : keyboard{0}
	{
		instance = this;
	}

	void Input::Tick()
	{
		// Clear the changes
		keyboardChanges = std::set<int>();
	}

	void Input::KeyChangeState(int key, int state)
	{
		keyboardChanges.insert(key);
		keyboard[key] = state;
	}

	bool Input::KeyDown(int key)
	{
		return keyboard[key] == 1;
	}

	bool Input::OnKeyDown(int key)
	{
		return KeyDown(key) && keyboardChanges.find(key) != keyboardChanges.end();
	}

	bool Input::KeyUp(int key)
	{
		return !KeyDown(key);
	}

	bool Input::OnKeyUp(int key)
	{
		return KeyUp(key) && keyboardChanges.find(key) != keyboardChanges.end();
	}
}