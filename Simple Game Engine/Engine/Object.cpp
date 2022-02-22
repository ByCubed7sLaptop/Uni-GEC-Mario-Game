#include "Object.h"

namespace Core {
	Object::Object(std::string name)
	{
		this->name = name;
	}

	Core::Object::operator std::string()
	{
		return name;
	}
}