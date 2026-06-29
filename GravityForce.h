#pragma once

#include "IForceGenerator.h"

class GravityForce : public IForceGenerator
{
private:
	double acceleration;

public:
	GravityForce(double gravitational_acceleration)
		: acceleration(gravitational_acceleration) {}

	virtual void Apply(Body& body)
	{
		body.ApplyForce(Vector2D(0, body.GetMass() * acceleration));
	}
};

