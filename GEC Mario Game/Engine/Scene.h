#pragma once

#include "Object.h"
#include "Storable.h"
#include "Vector.h"

#include <SDL.h>
#include <stdio.h>

#include <set>

namespace Core {

	// Forward declaration
	class GameObject;
	class Component;
	class Collider;
	class Renderer;

	// A Data structure for a loadable game scene
	class Scene : public Object, public Storable
	{
	public:
		Scene();

		std::set<GameObject*> gameObjects;
		std::set<Component*> components;
		std::set<Collider*> colliders;
		std::map<Collider*, Collider*> inCollision;

		bool Update(Uint32 deltaTime);
		bool Render(SDL_Renderer* renderer);
		
		void CalculateCollisions();

		std::set<Collider*> BoxTrace(Vector<float, 4> box, Collider* exclude = nullptr);
		
		/// <summary>
		/// Gets the intersecting position of 2 ongoing lines. Assumes the lines are NOT parallel.
		/// </summary>
		/// <param name="lineA">- The first line {sp1,sp2,ep1,ep2}</param>
		/// <param name="lineB">- The second line {sp1,sp2,ep1,ep2}</param>
		/// <returns>The point at which the lines intersect</returns>
		Vector<float, 2> LineIntersection(Vector<float, 4> lineA, Vector<float, 4> lineB);


		GameObject* CreateGameObject();

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