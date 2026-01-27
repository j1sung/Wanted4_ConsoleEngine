#pragma once
#include "Common/Common.h"

namespace Wanted
{
	// 전방 선언.
	class Input;

	// Main game engine class.
	// 행동 전용.
	class WANTED_API Engine
	{
		
	public:
		Engine();
		~Engine();

		// 엔진 루프(게임 루프).
		void Run();

		// 엔진 종료 함수.
		void QuitEngine();

		// 새 레벨을 추가(설정)하는 함수.
		void SetNewLevel(class Level* newLevel); // 전방선언

	private:// 이건 감추기!

		// 게임 플레이 시작 함수.
		// Unity의 경우: Start/Awake.
		void BeginPlay();

		// 업데이트 함수
		void Tick(float delthTime); // 프레임 시간을 계산해서 주입 필요

		// 그리기 함수. (Draw/Render).
		void Draw();

	private:
		// 엔진 종료 플래그. -> 조건부 무한루프를 만들거기 때문에 필요!
		bool isQuit = false;

		// 입력 관리자.
		Input* input = nullptr;

		// 메인 레벨.
		class Level* mainLevel = nullptr; // 전방선언
	};

}


