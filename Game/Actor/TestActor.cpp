#include "TestActor.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include <iostream>
#include <Windows.h>

using namespace Wanted;

TestActor::TestActor()
	//: Actor()
	: super('T', Vector2(5,5))
{
}

void TestActor::BeginPlay()
{
	// 상위 함수 호출
	// C++는 부모함수 가리키는 포인터가 없음
	Actor::BeginPlay(); // Actor:: 는 상위 멤버 함수를 가리킴

	std::cout << "TestActor::BeginPlay().\n";
}

void TestActor::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// Q키 종료.
	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// Todo: 게임 엔진 종료 요청.
		Wanted::Engine::Get().QuitEngine();
	}

	// 이동.
	// if(Input::Get().GetKey('D'))
	if (Input::Get().GetKey(VK_RIGHT) && GetPosition().x <20)
	{
		Vector2 newPosition = GetPosition();
		newPosition.x += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_LEFT) && GetPosition().x > 0)
	{
		Vector2 newPosition = GetPosition();
		newPosition.x -= 1;
		SetPosition(newPosition);
	}

	//std::cout << "TestActor::Tick().deltaTime: " << deltaTime 
	//	<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
