#include "Window.h"

#include <iostream>

#include <SDL.h>
#include <stdio.h>

namespace Core {

	Window::Window(std::string name)
	{
        title = name;
	}

    Vector<int, 2> Window::Size()
    {
        return size;
    }

    void Window::SetSize(Vector<int, 2> newSize)
    {
        size = newSize;
    }

}

