#pragma once

#include "Object.h"
#include "Vector.h"

#include <vector>

namespace Core {

	// Forward
	class Collider;

	class Collision
	{
	public:
		Collision(Collider* colliderA, Collider* colliderB);

		// Collision point
		Vector<float, 2> point;

		// Colliders
		Collider* colliderA;
		Collider* colliderB;

		// Velocities
		Vector<float, 2> colliderAVelocity;
		Vector<float, 2> colliderBVelocity;
	};

}