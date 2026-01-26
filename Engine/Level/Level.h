#pragma once

// STL(Standard Template Library - C++ 에서 기본 제공)
// 크기가 알아서 변경되는 배열.
#include <vector>

namespace Wanted
{
	// 전방 선언.
	class Actor;

	// 담당임무: 레벨에 있는 모든 액터(물체) 관리
	class Level
	{
	public:
		Level();
		virtual ~Level();

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

	protected:
		// 액터 배열.
		std::vector<Actor*> actors; // 전방선언
	};



}
