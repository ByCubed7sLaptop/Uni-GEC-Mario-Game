#pragma once

#include "Object.h"

#include <set>

namespace Core {

	// Forward declaration
	class GameObject;
	class Components;
	class Renderer;

	// A Data structure for a loadable game scene
	class Scene : public Object
	{
		std::set<GameObject*> gameObjects;
		std::set<Components*> components;

		bool Render(Renderer* renderer);
		
		bool Load(std::string filepath);
		bool Save(std::string filepath);

	private:
		static Scene LoadFromFile(std::string filepath);
		static Scene SaveToFile(std::string filepath);
	};

}