#include "Player.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include "Actor/Box.h"
#include "Level/Level.h"

#include <iostream>
#include <Windows.h>

using namespace Wanted;

Player::Player()
	//: Actor()
	: super('P', Vector2(5,5), Color::Red)
{
}

void Player::BeginPlay()
{
	// 상위 함수 호출
	// C++는 부모함수 가리키는 포인터가 없음
	Actor::BeginPlay(); // Actor:: 는 상위 멤버 함수를 가리킴

	std::cout << "TestActor::BeginPlay().\n";
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// Q키 종료.
	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// Todo: 게임 엔진 종료 요청.
		Wanted::Engine::Get().QuitEngine();
	}

	// 스페이스로 박스 생성.
	// VK->virtual key 가상키
	if (Input::Get().GetKeyDown(VK_SPACE)) 
	{
		// 박스 생성. level 포인터
		if (owner) // 포인터는 null 체크 하면 좋다.
		{
			owner->AddNewActor(new Box(GetPosition()));
		}
	}

	// 이동.
	// if(Input::Get().GetKey('D'))
	if (Input::Get().GetKey(VK_RIGHT) && GetPosition().x < 20)
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

	if (Input::Get().GetKey(VK_DOWN) && GetPosition().y < 15)
	{
		Vector2 newPosition = GetPosition();
		newPosition.y += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_UP) && GetPosition().y > 0)
	{
		Vector2 newPosition = GetPosition();
		newPosition.y -= 1;
		SetPosition(newPosition);
	}

	//std::cout << "TestActor::Tick().deltaTime: " << deltaTime 
	//	<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Player::Draw()
{
	Actor::Draw();
}
