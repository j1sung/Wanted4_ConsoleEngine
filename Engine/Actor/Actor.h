#pragma once

namespace Wanted
{

	class Actor
	{
	public:
		Actor();
		virtual ~Actor();// virtual 을 써야 자식객체로 생성할때 소멸자 호출됨

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

	protected:

	};

}

