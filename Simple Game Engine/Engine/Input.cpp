#include "Input.h"
#include <iostream>

namespace Core {

	Input* Input::instance = nullptr;

	Input::Input()
	{
		std::cout << "Instance called" << std::endl;
		instance = this;
	}

	void Input::Tick()
	{
		// Clear the changes
		keyboardChanges = std::set<unsigned int>();
	}

	void Input::KeyChangeState(unsigned int key, int state)
	{
		keyboardState.emplace(key, state);
		keyboardChanges.insert(key);
	}

	bool Input::KeyDown(unsigned int key)
	{
		return keyboardState[key] == 1;
	}

	bool Input::OnKeyDown(unsigned int key)
	{
		return KeyDown(key) && keyboardChanges.find(key) != keyboardChanges.end();
	}

	bool Input::KeyUp(unsigned int key)
	{
		return !KeyDown(key);
	}

	bool Input::OnKeyUp(unsigned int key)
	{
		return KeyUp(key) && keyboardChanges.find(key) != keyboardChanges.end();
	}
}