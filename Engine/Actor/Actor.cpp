#include "Actor.h"
#include "Util/Util.h"
#include "Render/Renderer.h"

#include <iostream>
#include <Windows.h>

namespace Wanted 
{
	Actor::Actor(const char* image, const Vector2& position, Color color) // 초기값은 헤더에만 줌
		:position(position), color(color)
	{
		// 문자열 복사.
		size_t length = strlen(image) + 1;
		this->image = new char[length];
		strcpy_s(this->image, length, image);
	}
	Actor::~Actor()
	{
		// 메모리 해제.
		SafeDeleteArray(image);
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
		//Renderer::Draw(position, color, image);
		
		
		// 렌더러에 데이터 제출.
		Renderer::Get().Submit(image, position, color, sortingOrder); // 액터는 그리는데 필요한 데이터 주고 렌더러가 그림

		//// 액터의 현재 좌표로 콘솔 좌표 위치 이동.
		//Util::SetConsolePosition(position);
		//
		//// 이동한 좌표에서 글자 그리기.
		//std::cout << image;
	}
	void Actor::SetPosition(const Vector2& newPosition)
	{
		// 렌더러에 빈칸 그리기 요청.
		//Renderer::Draw(position, ' ');

		//// 액터의 현재 좌표로 콘솔 좌표 위치 이동.
		//Util::SetConsolePosition(position);
		//
		//// 해당 위치의 글자 값 지우기 (빈칸 그리기).
		//std::cout << ' ';

		// 변경하려는 위치가 현재 위치와 같으면 건너뜀.
		if (position == newPosition)
		{
			return;
		}

		// 새로운 위치 설정.
		position = newPosition;
	}
}