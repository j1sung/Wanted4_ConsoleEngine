#pragma once

#include "Level/Level.h"

class TestLevel: public Wanted::Level
{
	RTTI_DECLARATIONS(TestLevel, Level)

public:
	TestLevel();

private:
	// 게임에서 사용할 맵을 로드하는 함수.
	void LoadMap(const char* filename);
};

