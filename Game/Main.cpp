#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/SokobanLevel.h"
//#include "Actor/TestActor.h"
//#include "Level/Level.h"
//#include "Actor/Actor.h"

#include <iostream>

using namespace Wanted;

int main()
{
	// 예시 배열.
	const int width = 3;
	const int height = 3;
	CHAR_INFO charArray[width * height] = {};

	charArray[2 * width + 1].Char.AsciiChar = 'P';
	charArray[2 * width + 1].Attributes = FOREGROUND_GREEN;

	charArray[0 * width + 1].Char.AsciiChar = '#';
	charArray[0 * width + 1].Attributes = FOREGROUND_RED;

	COORD position = {};
	COORD screenSize;
	screenSize.X = width;
	screenSize.Y = height;

	SMALL_RECT writeRegion{
		0,
		0,
		static_cast<short>(width),
		static_cast<short>(height)
	};

	WriteConsoleOutputA(
		GetStdHandle(STD_OUTPUT_HANDLE),
		charArray,
		screenSize,
		position,
		&writeRegion
	);

	//CreateConsoleScreenBuffer(); // 화면에 보이게 전환
	//SetConsoleActiveScreenBuffer();
	


	//Wanted::Engine engine;
	//engine.SetNewLevel(new SokobanLevel());
	//engine.Run();

	/*Game game;
	game.Run();*/

	// 문자 배열을 한번에 콘솔로 넘겨서 그릴 때 사용하는 함수.
	//WriteConsoleOutputA();
	std::cin.get();

	//TestLevel* level = new TestLevel();
	//Actor* actor = new TestActor(); // 형변환 성공
	////Actor* actor = new Actor(); //-> 형변환 실패(else)
	//TestActor* testActor = new TestActor();

	///*if (actor->Is(testActor))
	//{
	//	std::cout << "actor is TestActor Type\n";
	//}
	//else
	//{
	//	std::cout << "actor is not TestActor Type\n";
	//}*/
	//
	////TestActor* testActor2 = dynamic_cast<TestActor*>(actor); // 밑에와 같다.
	//TestActor* testActor = actor->As<TestActor>();
	//if (testActor)
	//{
	//	std::cout << "actor is TestActor type. \n";
	//}
	//else
	//{
	//	std::cout << "actor is not TestActor type.\n";
	//}

	//std::cin.get();
}