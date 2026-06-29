#pragma once

#include "Body.h"

class IForceGenerator
{
public:
	virtual void Apply(Body& body) = 0;
	virtual ~IForceGenerator()     = default;
};

