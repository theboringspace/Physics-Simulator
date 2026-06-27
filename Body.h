#pragma once

#include "Vector2D.h"

/**********************************************************************
 * CLASS Body
 * -------------------------------------------------------------------
 *		All interactions studied in Physics relies on Body -- a 
 * collection of bodies that contain mass and can influence one 
 * another.
 *		Commonly measured attributes of a Body are as follows:
 * Position, Velocity, and Acceleration.
 *		A Force Accumulator variable is also measured at every change 
 * in time(dt) obtained from forces affecting the body.
 *********************************************************************/
class Body
{
private:
	Vector2D position, velocity, acceleration, force_accumulator;
	double mass;
public:
	// Getters & Setters
	Vector2D GetPosition()const         { return position; }
	Vector2D GetVelocity()const         { return velocity; }
	Vector2D GetAcceleration()const     { return acceleration; }
	Vector2D GetForceAccumulator()const { return force_accumulator; }
	double GetMass()const { return mass; }

	void SetPosition(Vector2D position_)				  { position          = position_; }
	void SetVelocity(Vector2D velocity_)				  { velocity		  = velocity_; }
	void SetAcceleration(Vector2D acceleration_)		  { acceleration	  = acceleration_; }
	void SetForceAccumulator(Vector2D force_accumulator_) { force_accumulator = force_accumulator_; }

	// Constructor
	Body(Vector2D position_, double mass_)
		: position(position_), velocity(0, 0), acceleration(0, 0), mass(mass_) {}

	// Member Functions
	void ApplyForce(Vector2D force)
	{
		force_accumulator = force_accumulator + force;
	}

	void Integrate(double dt)
	{
		acceleration = force_accumulator * (1.0 / mass);

		velocity = velocity + acceleration * dt;

		position = position + velocity * dt;

		force_accumulator = Vector2D(0, 0);
	}
};