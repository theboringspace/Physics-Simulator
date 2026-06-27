#pragma once

#include "Body.h"
#include <vector>

class World
{
private:
	std::vector<Body> bodies;

public:
	std::vector<Body>& GetBodies() { return bodies; }

	void AddBody(const Body& body)
	{
		bodies.push_back(body);
	}

	void Update(double dt)
	{
		for (auto& body : bodies)
			body.Integrate(dt);
	}
};

