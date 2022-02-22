#pragma once

#include <string>

namespace Core {
	struct Object
	{
		Object(std::string name);

		std::string name;

		// Casting to string
		operator std::string();
	};
}

