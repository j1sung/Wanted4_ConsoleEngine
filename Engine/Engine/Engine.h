#pragma once

namespace Wanted
{
	// Main game engine class.
	// 행동 전용.
	class Engine
	{
		// 클래스, 구조체 구조적으로 차이가 없으니 정해서 쓰자.
		// 데이터 전용.
		// Down/Up/Key
		struct KeyState
		{
			// 현재 키가 눌렸는지.
			bool isKeyDown = false;
			
			// 이전에 키가 눌렸는지.
			bool wasKeyDown = false;
		};

	public:
		Engine();
		~Engine();

		// 엔진 루프(게임 루프).
		void Run();

		// 엔진 종료 함수.
		void QuitEngine();

		// 입력 확인 함수.
		// 이전에 입력이 안됐는데, 현재 입력이 됐으면 1번 호출.
		bool GetKeyDown(int keyCode);

		// 이전에 입력이 됐는데, 현재 입력이 취소 됐으면 1번 호출.
		bool GetKeyUp(int keyCode);

		// 현재 눌려있으면 반복 호출.
		bool GetKey(int keyCode);

	private:// 이건 감추기!
		// 입력 처리 함수.
		void ProcessInput();

		// 업데이트 함수
		void Tick(float delthTime); // 프레임 시간을 계산해서 주입 필요

		// 그리기 함수. (Draw/Render).
		void Draw();

	private:
		// 엔진 종료 플래그. -> 조건부 무한루프를 만들거기 때문에 필요!
		bool isQuit = false;

		// 키 상태 저장용 배열.
		KeyState keyStates[255] = { }; // 255개면 모든키 다 받을 수 있다. -> 게임패드 + 키보드(다국적 자판 포함)
	};

}


