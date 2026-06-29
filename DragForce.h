#pragma once

#include "IForceGenerator.h"

class DragForce : public IForceGenerator
{
private:
	double drag_coefficient;

public:
	DragForce(double coef) : drag_coefficient(coef) {}

	virtual void Apply(Body& body)
	{
		body.ApplyForce(body.GetVelocity() * (-drag_coefficient));
	}
};