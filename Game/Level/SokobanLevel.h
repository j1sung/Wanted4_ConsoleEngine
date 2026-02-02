#pragma once

#include "Level/Level.h"
#include "Interface/ICanPlayerMove.h" // 인터페이스

class SokobanLevel: public Wanted::Level, public ICanPlayerMove // 인터페이스 상속 & 구현
{
	RTTI_DECLARATIONS(SokobanLevel, Level)

public:
	SokobanLevel();

private:
	// 게임에서 사용할 맵을 로드하는 함수.
	void LoadMap(const char* filename);

	// Inherited via ICanPlayerMove
	virtual bool CanMove(
		const Wanted::Vector2& playerPosition, 
		const Wanted::Vector2& nextPosition) override;
};

