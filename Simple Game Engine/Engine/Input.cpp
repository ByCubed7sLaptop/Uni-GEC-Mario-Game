#include "Input.h"
#include <iostream>

namespace Core 
{
	std::map<unsigned int, int> Input::keyboardState = std::map<unsigned int, int>();
	std::set<unsigned int> Input::keyboardChanges = std::set<unsigned int>();

	void Input::Tick()
	{
		//std::cout << "Tick" << std::endl;

		// Clear the changes
		keyboardChanges = std::set<unsigned int>();
	}

	void Input::KeyChangeState(unsigned int key, int state)
	{
		keyboardState[key] = state;
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