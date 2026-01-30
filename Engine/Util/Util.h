#pragma once

#include "Math/Vector2.h"
#include "Math/Color.h"

//using namespace std; // 워낙 카테고리 방대, 제공하는게 많아서 넓은 범위는 안쓰는게 좋다고...

using namespace Wanted;

// 헬퍼(Helper) 기능 제공.
namespace Util
{
	// 헤더에서 전역에 구현한 함수가 있을때 이 헤더가 여러곳에 중복 쓰이면 링커 오류 뜸
	// 1. 인라인
	// 2. static
	// 3. cpp와 h로 분리 -> 정석 방법

	// 콜스택이 많을때 인라인이 잘 안될때가 있어 조심해야함
	inline void SetConsolePosition(const Vector2& position)
	{
		//COORD coord = {};
		//coord.X = static_cast<short>(position.x);
		//coord.Y = static_cast<short>(position.y);

		// 콘솔 커서 위치 이동(설정)하는 함수.
		SetConsoleCursorPosition(//  COORD 좌표값
			GetStdHandle(STD_OUTPUT_HANDLE),
			static_cast<COORD>(position) // 이제 형변환 만든거로 교체
		);
	}

	// 콘솔 텍스트 설정 함수.
	inline void SetConsoleTextColor(Color color)
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			static_cast<unsigned short>(color)
		);
	}

	// 커서 끄기.
	inline void TurnOffCursor()
	{
		// 커서 끄기.
		CONSOLE_CURSOR_INFO info = {};
		GetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);

		info.bVisible = false; // Off
		SetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);
	}

	// 커서 켜기.
	inline void TrunOnCursor()
	{
		// 커서 끄기.
		CONSOLE_CURSOR_INFO info = {};
		GetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);

		info.bVisible = true; // true = ON
		SetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);
	}
}