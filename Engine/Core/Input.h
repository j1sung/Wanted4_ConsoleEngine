#pragma once

#include "Common/Common.h"

namespace Wanted 
{
	class WANTED_API Input
	{
		friend class Engine;

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

	private:
		Input();

	//public: // 소멸자는 public이어도 된다.
		~Input();

	public:
		// 입력 확인 함수.
		// 이전에 입력이 안됐는데, 현재 입력이 됐으면 1번 호출.
		bool GetKeyDown(int keyCode);

		// 이전에 입력이 됐는데, 현재 입력이 취소 됐으면 1번 호출.
		bool GetKeyUp(int keyCode);

		// 현재 눌려있으면 반복 호출.
		bool GetKey(int keyCode);

		// 전역적으로 접근하는 함수.
		static Input& Get(); // 포인터는 권한을 많이 주는데 &래퍼런스 쓰면 주소를 변경하고 뭐 못하니 많이 씀

	private:
		// 입력 처리 함수.
		void ProcessInput(); // friend로 Engine해서 열어둠 점근!!

		// 기존 입력 저장 함수.
		void SavePreviousInputStates();

	private:
		// 키 상태 저장용 배열.
		KeyState keyStates[255] = { }; // 255개면 모든키 다 받을 수 있다. -> 게임패드 + 키보드(다국적 자판 포함)

		// 전역적으로 접근하도록 만들기 위한 전역 변수.
		static Input* instance;
	};


}
