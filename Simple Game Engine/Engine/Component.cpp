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

		scene = owner->GetScene();
		scene->components.insert(this);
	}

	GameObject* Component::Owner() { return gameObject; }
	Scene* Component::GetScene() { return scene; }

	void Component::Draw(SDL_Renderer* renderer) {}
}