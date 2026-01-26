#include <iostream>
#include "Engine/Engine.h"
#include "Level/TestLevel.h"



int main()
{
	Wanted::Engine engine;
	engine.SetNewLevel(new TestLevel()); // TestLevel 힙에 생성
	engine.Run();
	// engine->Run(); -> 이렇게 힙으로 굳이 안써도 될땐 스택으로 그냥

	std::cin.get();
	return 0;
}
