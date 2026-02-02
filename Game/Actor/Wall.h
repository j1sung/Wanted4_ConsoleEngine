#pragma once
#include "Actor/Actor.h"

using namespace Wanted;

class Wall : public Wanted::Actor
{
	RTTI_DECLARATIONS(Wall, Actor) // Wall 은 Actor의 자손

public:
	// 위치 지정이 가능하도록 생성자 선언.
	Wall(const Vector2& position);
};

