#pragma once

#include "Common/RTTI.h"
#include "Math/Vector2.h"
#include "Math/Color.h"

namespace Wanted
{
	// 전방 선언. -> 왜 포인터로만 될까? - 클래스/구조체 정보 컴파일 넘어갈때 데이터 크기 문제 없어야/ 메모리 공간 확보, 포인터 주소 제공, 포인터는 8바이트 크기로 통일, 
	class Level;

	class WANTED_API Actor : public RTTI
	{

		// RTTI 코드 추가
		RTTI_DECLARATIONS(Actor, RTTI)

	public:
		Actor(
			const char image = ' ',
			const Vector2& position = Vector2::Zero,
			Color color = Color::White
		);
		virtual ~Actor();// virtual 을 써야 자식객체로 생성할때 소멸자 호출됨

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// 위치 변경 및 읽기 함수.
		void SetPosition(const Vector2& newPosition);
		inline Vector2 GetPosition() const { return position; }

		// 오너쉽 추가/읽기 함수.
		inline void SetOwner(Level* newOwner) { owner = newOwner; }
		inline Level* GetOwner() const { return owner; }

		// Getter.
		inline bool HasBeganPlay() const 
		{ 
			return hasBeganPlay; 
		}
		
		inline bool IsActive() const
		{
			return isActive && !destroyRequested;
		}
		
		inline bool DestroyRequested() const 
		{
			return destroyRequested; 
		}

		inline int GetSortingOrder() const 
		{ 
			return sortingOrder; 
		}

	protected:
		// 이미 BeginPlay 이벤트를 받았는지 여부.
		bool hasBeganPlay = false;

		// 활성화 상태 여부.
		bool isActive = true;

		// 현재 프레임에 삭제 요청 받았는지 여부.
		bool destroyRequested = false;

		// 그릴 문자(이미지).
		char image = ' ';

		// 색상.
		Color color = Color::White;

		// 오너쉽(Ownership).
		Level* owner = nullptr; // 포인터 아니면 안됨 -> 불안전

		// 그리기 우선 순위 (값이 크면 우선순위가 높음).
		int sortingOrder = 0;

	private:
		// 위치.
		Vector2 position; // Get/Set 필요
	};

}