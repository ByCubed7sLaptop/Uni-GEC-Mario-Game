#pragma once

#include "Object.h"

#include <set>

namespace Core {

	// Forward declaration
	class GameObject;
	class Components;

	// A Data structure for a loadable game scene
	class Scene : public Object
	{
		std::set<GameObject*> gameObjects;
		std::set<Components*> components;
	};

}