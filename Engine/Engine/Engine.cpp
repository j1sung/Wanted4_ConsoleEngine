#include "Engine.h"
#include "Level/Level.h"
#include "Core/Input.h"

#include <iostream>
#include <windows.h> // 입력 처리시 -> 윈도우가 처리하니

// 네임스페이스 만든 후에 선언/정의 만들기 하면 안으로 잘 만들어줌
namespace Wanted
{
	Engine::Engine()
	{
		// 입력 관리자 생성
		input = new Input();
	}

	Engine::~Engine()
	{
		// 메인 레벨 제거
		if (mainLevel)
		{
			delete mainLevel;
			mainLevel = nullptr;
		}

		// 입력 관리자 제거
		if (input)
		{
			delete input;
			input = nullptr;
		}
	}

	void Engine::Run()
	{
		// 시계의 정밀도. -> 1초에 몇번 진동하는지?
		LARGE_INTEGER frequency; // 주파수
		QueryPerformanceFrequency(&frequency);

		// 프레임 계산용 변수. -> 프레임 = 현재시간 - 이전 시간
		//__int64
		int64_t currentTime = 0;
		int64_t previousTime = 0;

		// 하드웨어 타이머로 시간 구하기.
		LARGE_INTEGER time; 
		QueryPerformanceCounter(&time); // 함수 실행 현재 시간
		// 하드웨어 타이머 -> 보통은 cpu에서 읽음 -> 1천만 이상으론 안나오는,,,

		// 엔진 시작 직전에는 두 시간 값을 같게 맞춤.
		// 첫 프레임은 이전시간 뺄 수 없어서 계산이 안되는데 일단 넣어놔야함.
		// 첫 프레임 계산에서 두개를 같게 두고 빼면 0이 나오고 이걸 무시한다.
		currentTime = time.QuadPart;
		previousTime = currentTime; 

		// 7
		// 기준 프레임(단위: 초).
		// 모든 계산에선 단위가 항상 같아야 한다. 프레임 말고도.
		float targetFrameRate = 120.0f; // 1초에 240fps
		float oneFrameTime = 1.0f / targetFrameRate; // 1/240

		// 엔진 루프(게임 루프).
		// !-> Not -> bool값 뒤집기.
		while (!isQuit) // isQuit == null
		{
			//timeGetTime(); // 밀리초 단위로 검색함 -> 가장 작은 단위 = 0.001초 -> 1/120(0.008...) 이상부턴 제대로 계산이 불가,,,

			// 현재 시간 구하기
			QueryPerformanceCounter(&time); // 1000만분의 1 정밀도
			currentTime = time.QuadPart;
			
			
			// 프레임 시간 계산 -> 원하는건 초 단위의 시간이다.
			float deltaTime
				= static_cast<float>(currentTime - previousTime);

			// 초단위 변환.
			deltaTime = deltaTime
				/ static_cast<float>(frequency.QuadPart);

			// 고정 프레임 기법.
			if (deltaTime >= oneFrameTime)
			{
				intput->ProcessInput(); // 키가 눌리는지 확인 가능

				// 프레임 처리.
				BeginPlay(); // 매 프레임 X -> 처음 1번만 호출되게 = Awake
				Tick(deltaTime); // 현재시간 기준 이전값 계산
				Draw();

				// 이전 시간 값 갱신.
				previousTime = currentTime;

				input->SavePreviousInputStates();
			}
		}

		// Todo: 정리 작업.
		std::cout << "Engine has been shutdown....\n";
	}
	void Engine::QuitEngine()
	{
		isQuit = true;
	}
		
	void Engine::SetNewLevel(Level* newLevel)
	{
		// 기존 레벨 있는지 확인
		// 있으면 기존 레벨 제거.
		// @Todo: 임시 코드. 레벨 전환할 때는 바로 제거하면 안됨.
		if (mainLevel)
		{
			delete mainLevel;
			mainLevel = nullptr;
		}

		// 레벨 설정.
		mainLevel = newLevel;
	}

	
	void Engine::BeginPlay()
	{
		// 레벨이 있으면 이벤트 전달.
		// if(mainLevel) 로 되는걸 감싸는거보다 오류를 먼저 위에서 검출하고 밑에서 통과하는식으로 가는게 보기 편하고 좋다.
		if (!mainLevel) 
		{
			// Silent is violent.
			// 침묵은 폭력이다.
			// -> 로그 메시지 안남기면 나빠
			std::cout << "mainLevel is empty.\n";
			return;
		}
		mainLevel->BeginPlay();
	}

	void Engine::Tick(float deltaTime)
	{
		//std::cout 
		//	<< "DeltaTime: " << deltaTime
		//	<< ", FPS: " << (1.0f / deltaTime) << "\n";

		//// ESC키 눌리면 종료.
		if (input->GetKeyDown(VK_ESCAPE))
		{
			QuitEngine();
		}

		// 레벨에 이벤트 흘리기
		// 예외 처리
		if (!mainLevel)
		{
			std::cout << "Error: Engine::Tick(). mainLevel is empty.\n";
			return;
		}

		mainLevel->Tick(deltaTime);
	}

	void Engine::Draw()
	{
		// 레벨에 이벤트 흘리기
		// 예외 처리
		if (!mainLevel)
		{
			std::cout << "Error: Engine::Draw(). mainLevel is empty.\n";
			return;
		}

		mainLevel->Draw();
	}
}
