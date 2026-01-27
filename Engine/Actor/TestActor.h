#pragma once

#include "Actor.h"

class WANTED_API TestActor : public Wanted::Actor
{
public:
protected: // 상속해서 추가 구현할때 virtual + override를 같이 붙이는게 좋음!
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

