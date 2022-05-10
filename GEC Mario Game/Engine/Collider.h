#pragma once

#include "Object.h"
#include "Vector.h"
#include "Component.h"

#include <vector>

namespace Core {

	class Collider : public Component
	{
	public:

		enum State {
			ACTIVE,
			ASLEEP
		};

		Collider(GameObject* owner);

		void Update(float deltaTime) override;
		void Draw(SDL_Renderer* renderer) override;

		Collider* SetShape(std::vector<Vector<float, 2>> newPoints);
		bool ContainsPoint(Vector<float, 2> position);

		void OnCollisionEnter(Collider* otherCollider);
		void OnCollisionStay(Collider* otherCollider);
		void OnCollisionExit(Collider* otherCollider);

		bool IsActive();
		bool IsAsleep();
		bool IsKinematic();

		Collider* AddForce(Core::Vector<float, 2> force);
		// Collision points
		std::vector<Vector<float, 2>> points;

		// Offset
		Vector<float, 2> offset;

		// Axis Aligned Bounding Box
		Vector<float, 2> aabb;
		virtual Vector<float, 4> Bounds();

		// Whether the collider can move via physics
		bool kinematic;

		// The static of a collider
		State state;

		// The resistance to CHANGE of velocity
		float mass;

		// The resistance to velocity
		float airDensity;

		// Linear momentum
		Vector<float, 2> velocity;

		// Angular momentum
		float torque;
	};

}