#pragma once

#include "Util/Util.h"
#include <iostream>
#include <vector>

namespace Wanted
{
	// 이해를 돕기 위함
	//struct RenderCommand
	//{
	//	// 그리는데 필요한 데이터.
	//	Vector2 position;
	//	Color color = Color::White;
	//	char image = ' ';
	//};

	// DLL 내부에서만 사용하도록.
	class Renderer // 원래는 Renderer 자체로직에서 Drawcall을 하게 해야함. 
	{              // 지금은 Actor에서 하게 해놨지만, 원래는 Actor는 데이터들만 주고 Renderer에서 받아서 싱글톤으로 데이터 받아서 루프를 돌며 Draw를 돌리는 방식을 씀
		           // 지금 만든 콘솔 엔진은 컴포넌트를 구현 안했는데 원래는 Renderer 컴포넌트가 있어서, 모든 컴포넌트를 받는데 Renderer컴포넌트만 모아서 빼서 나중에 한번에 돌림
		           // 마지막에 한번에 Drawcall을 보낸다.
		           // cpu쪽에선 잘게 쪼개서 gpu에 보내고, gpu는 최대한 모아서 한번에 처리해야 cpu와 gpu가 모두 효율적으로 잘 쓰면서 성능이 좋아지는데 
				   // 이 Renderer가 그리기 자료를 모아서 처리해주기때문에 연결되어있고, Renderer는 메인 스레드와 따로 스레드가 있고 거기서 돌면서 gpu와 일을 한다.
	public:
		// 그리기 함수.
		static void Draw(const char image)
		{
			//// 예시.
			//for (auto& command : commands)
			//{
			//	Draw(command.position, command.color, command.image);
			//}

			std::cout << image;
		}

		// 1.위치 설정 및 2.그리기 한번에 처리하는 함수.
		static void Draw(const Vector2& position, const char image)
		{
			Util::SetConsolePosition(position);
			Draw(image);
		}

		// 1.위치, 2.색상 설정 및 3.그리기.
		static void Draw(const Vector2& position, Color color, const char image)
		{
			// 커서 위치 설정.
			Util::SetConsolePosition(position); 

			// 텍스트 색상 설정.
			Util::SetConsoleTextColor(color);

			// 글자 출력.
			Draw(image);

			// 원래 색상으로 다시 설정 (흰색으로).
			Util::SetConsoleTextColor(Color::White);
		}

	private:
		//static std::vector<RenderCommand> commands;
	};
}