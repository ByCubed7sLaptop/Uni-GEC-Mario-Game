#include "Component.h"
#include "GameObject.h"

#include "Object.h"

namespace Core 
{
	Component::Component(GameObject* owner)
		: Object("Component")
	{
		gameObject = owner;
	}

	GameObject* Component::Owner()
	{
		return gameObject;
	}

}