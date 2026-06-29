#pragma once

#include "Body.h"
#include "IForceGenerator.h"
#include <vector>

class World
{
private:
	std::vector<Body> bodies;
	std::vector<IForceGenerator*> forces;

public:
	std::vector<Body>& GetBodies() { return bodies; }

	void AddBody(const Body& body)
	{
		bodies.push_back(body);
	}

	void Update(double dt)
	{
		for (auto& force : forces)
		{
			for (auto& body : bodies)
			{
				force->Apply(body);
			}
		}

		for (auto& body : bodies)
		{
			body.Integrate(dt);
		}
	}

	void AddForceGenerator(IForceGenerator* force)
	{
		forces.push_back(force);
	}
};

