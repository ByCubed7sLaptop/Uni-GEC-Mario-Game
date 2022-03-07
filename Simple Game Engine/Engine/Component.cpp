#include "Component.h"
#include "GameObject.h"

#include "Object.h"
#include "Scene.h"

namespace Core 
{
	Component::Component(GameObject* owner)
		: Object("Component")
	{
		gameObject = owner;
		owner->GetScene()->components.insert(this);
	}

	GameObject* Component::Owner()
	{
		return gameObject;
	}

	void Component::Draw(SDL_Renderer* renderer) {}

	//void Component::Draw(SDL_Renderer* renderer) {}
}