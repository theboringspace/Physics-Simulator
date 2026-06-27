#pragma once

#include <math.h>

/**********************************************************************
 * CLASS Vector2D
 * -------------------------------------------------------------------
 *		All Physics is predicated upon constructs that have both
 * magnitude and direction.
 * 
 *		This class is essential to represent these various constructs.
 * -------------------------------------------------------------------
 *		The class will use the classic Cartesian coordinate system;
 * all vectors will be expressed in components of unit vectors: 
 * x and y that either point positively(right / up) or 
 * negatively(left / down)
 *********************************************************************/
class Vector2D
{
private:
	// Component Variables
	double x;
	double y;

public:
	/*
	 * Default and Overloaded Constructors
	 */
	Vector2D()
	{ 
		x = 0;
		y = 0;
	}

	Vector2D(double x_,
		     double y_)
			 : x(x_), y(y_) {}

	/*
	 * Getters
	 */
	double GetX()const { return x; }
	double GetY()const { return y; }

	/*
	 * FUNCTION Normalize
	 * --
	 * Rescales x and y when Magnitude = 1.
	 */
	void Normalize() 
	{ 
		double magnitude = GetMagnitude();

		if (magnitude == 0) { return; }

		x /= magnitude;
		y /= magnitude;
	}

	/*
	 * OPERATOR OVERLOAD +
	 * --
	 * Componential Addition.
	 */
	Vector2D operator +(const Vector2D& B)const
	{
		Vector2D resultant;

		double x_sum = x + B.x;
		double y_sum = y + B.y;

		resultant.x = x_sum;
		resultant.y = y_sum;

		return resultant;
	}

	/*
	 * OPERATOR OVERLOAD -
	 * --
	 * Componential Subtraction.
	 */
	Vector2D operator -(const Vector2D& B)const
	{
		Vector2D resultant;

		double x_diff = x - B.x;
		double y_diff = y - B.y;

		resultant.x = x_diff;
		resultant.y = y_diff;

		return resultant;
	}

	/*
	 * OPERATOR OVERLOAD * ; DOT PRODUCT
	 * --
	 * Typical Vector Dot Product calculation.
	 */
	double operator *(const Vector2D& B)const
	{

		return ( x * B.x + y * B.y );
	}

	/*
	 * OPERATOR OVERLOAD * ; SCALING OPERATION
	 * --
	 * Typical Vector Scaling operation.
	 */
	Vector2D operator *(double scalar)const
	{
		return Vector2D(x * scalar, y * scalar);
	}

	/*
	 * FUNCTION GetMagnitude
	 * --
	 * Calculates Length / Magnitude of Vector.
	 */
	double GetMagnitude()const
	{
		return sqrt( (x * x) + (y * y) );
	}
};

