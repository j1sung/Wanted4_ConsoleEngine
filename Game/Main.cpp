#include <iostream>
#include "Engine/Engine.h"
#include "Level/TestLevel.h"
//#include "Actor/TestActor.h"
//#include "Level/Level.h"
//#include "Actor/Actor.h"

using namespace Wanted;

int main()
{
	Wanted::Engine engine;
	engine.SetNewLevel(new TestLevel());
	engine.Run();

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