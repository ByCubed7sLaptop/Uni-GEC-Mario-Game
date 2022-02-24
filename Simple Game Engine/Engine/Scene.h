#pragma once

#include "Object.h"
#include "Storable.h"

#include <set>

namespace Core {

	// Forward declaration
	class GameObject;
	class Component;
	class Renderer;

	// A Data structure for a loadable game scene
	class Scene : public Object, public Storable
	{
	public:
		Scene();

		std::set<GameObject*> gameObjects;
		std::set<Component*> components;

		bool Render(Renderer* renderer);
		
		bool Load(std::string filepath);
		bool Save(std::string filepath);

	private:
		//static Scene LoadFromFile(std::string filepath);
		//static Scene SaveToFile(std::string filepath);

		// Returns the JSON format of the object 
		virtual std::string ToStorable() override;

		// Loads the object from the given json
		virtual bool FromStorable(std::string data) override;
	};

}