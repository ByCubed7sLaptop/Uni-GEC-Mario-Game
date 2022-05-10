#pragma once

#include "Vector.h"

#include <string>

namespace Core {
	class Window
	{
	public:
		Window(std::string name);
		//~Window();

		virtual void Update() = 0;

		Vector<int, 2> Size();
		void SetSize(Vector<int, 2> newSize);

	protected:
		std::string title;
		Vector<int, 2> size;
	};
}