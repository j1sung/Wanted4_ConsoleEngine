#pragma once

#include "Actor/Actor.h"

class TestActor : public Wanted::Actor
{
	RTTI_DECLARATIONS(TestActor, Actor)
public:
	TestActor();

protected: // 상속해서 추가 구현할때 virtual + override를 같이 붙이는게 좋음!
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

