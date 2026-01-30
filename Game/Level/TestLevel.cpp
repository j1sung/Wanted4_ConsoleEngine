#include "TestLevel.h"
#include "Actor/Player.h"
//#include "Core/Input.h"

TestLevel::TestLevel()
{
	/*if (Wanted::Input::Get().GetKeyDown('T'))
	{

	}*/

	// TestActor 액터를 레벨에 추가.
	AddNewActor(new Player());
}
