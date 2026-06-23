#include "GameBase.h"
#include <raylib.h>

namespace core
{
	GameBase::GameBase() {}

	GameBase::~GameBase() {}

	void GameBase::run()
	{
		while (!WindowShouldClose())
		{
			inputHandler();
			update();
			BeginDrawing();
			ClearBackground(BLACK);
			render();
			EndDrawing();
		}
	}
}