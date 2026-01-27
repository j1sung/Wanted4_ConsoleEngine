#include "TestActor.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include <iostream>

void TestActor::BeginPlay()
{
	// 상위 함수 호출
	// C++는 부모함수 가리키는 포인터가 없음
	Actor::BeginPlay(); // Actor:: 는 상위 멤버 함수를 가리킴

	std::cout << "TestActor::BeginPlay().\n";
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	// Q키 종료.
	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// Todo: 게임 엔진 종료 요청.
		Wanted::Engine::Get().QuitEngine();
	}

	std::cout << "TestActor::Tick().deltaTime: " << deltaTime 
		<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
