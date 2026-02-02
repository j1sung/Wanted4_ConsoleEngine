#pragma once
#include "Actor\Actor.h"

using namespace Wanted;

class Ground : public Wanted::Actor
{
	RTTI_DECLARATIONS(Ground, Actor)

public:
	Ground(const Vector2& position);
};

