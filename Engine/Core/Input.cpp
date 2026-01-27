#include "Input.h"
#include <Windows.h>
#include <iostream>

// Ctrl + Home키로 파일 제일 위로 이동 가능.
// Rider는 헤더 자동 추가 해줌.
namespace Wanted
{
	// 전역 변수 초기화.
	Input* Input::instance = nullptr;

	Input::Input()
	{
		// 객체가 초기화되면 자기 자신의 주소를 저장.
		instance = this;
	}
	Input::~Input()
	{
	}
	bool Input::GetKeyDown(int keyCode)
	{
		// 앞은 현재 키 눌리고(true) 뒤는 이전 키 안눌리고(false)
		return keyStates[keyCode].isKeyDown
			&& !keyStates[keyCode].wasKeyDown;
	}

	bool Input::GetKeyUp(int keyCode)
	{
		// 앞은 현재 키 안눌리고(false) 뒤는 이전 키 눌리고(true)
		return !keyStates[keyCode].isKeyDown
			&& keyStates[keyCode].wasKeyDown;
	}

	bool Input::GetKey(int keyCode)
	{
		// 현재 키 눌리면 true 반환
		return keyStates[keyCode].isKeyDown;
	}

	Input& Input::Get()
	{
		// 싱글턴(Singleton)
		// 이 함수는 콘텐츠 프로젝트에서 접근함.
		// 따라서 엔진은 이미 초기화 완료 상태
		if (!instance)
		{
			//return *nullptr;
			std::cout << "Error: Input::Get(). instance is null\n";

			// 디버그 모드에서만 동작함
			// 자동으로 중단점 걸림.
			__debugbreak();
		}

		// Lazy-Pattern.
		// 이펙티브 c++에 나옴.
		//static Input instance;
		// 엔진 시점에서는 잘 안쓰는 이유!
		// 1. 프로그램 끝날때까지 안쓰면 Input이 뭔 의미가 있는가?
		// 2. 초기화 시점 제어가 안됨. -> 엔진쪽에서 초기화하며 직접 관리하게

		return *instance;
	}

	void Input::ProcessInput() // 매 프레임마다 키가 눌렸는지 확인 가능
	{
		// 키 마다의 입력 읽기.
		// !!! 운영체제가 제공하는 기능을 사용할 수 밖에 없음.
		// window 기준이면 window.h 쓰자.
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].isKeyDown
				= GetAsyncKeyState(ix) & 0x8000 > 0 ? true : false;
		}

	}
	void Input::SavePreviousInputStates()
	{
		// 현재 입력 값을 이전 입력 값으로 저장.
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].wasKeyDown
				= keyStates[ix].isKeyDown;
		}
	}
}