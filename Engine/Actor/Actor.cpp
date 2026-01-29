#include "Actor.h"
#include <iostream>
#include <Windows.h>

namespace Wanted 
{
	Actor::Actor(const char image, const Vector2& position) // 초기값은 헤더에만 줌
		:image(image), position(position)
	{

	}
	Actor::~Actor()
	{

	}

	void Actor::BeginPlay()
	{
		// 이벤트를 받은 후에는 플래그 설정.
		hasBeganPlay = true;
	}
	void Actor::Tick(float deltaTime)
	{
		
	}
	void Actor::Draw()
	{
		// 액터의 현재 좌표로 콘솔 좌표 위치 이동.
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);

		SetConsoleCursorPosition(//  COORD 좌표값
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);

		// 이동한 좌표에서 글자 그리기.
		std::cout << image;
	}
	void Actor::SetPosition(const Vector2& newPosition)
	{
		// 액터의 현재 좌표로 콘솔 좌표 위치 이동.
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);

		SetConsoleCursorPosition(//  COORD 좌표값
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);

		// 해당 위치의 글자 값 지우기 (빈칸 그리기).
		std::cout << ' ';

		// 새로운 위치 설정.
		position = newPosition;
	}
}