#pragma once
#include "../Core/GameBase.h"

namespace core
{
	class GameTest : public GameBase
	{
	public:
		GameTest();
		~GameTest() override;

		void inputHandler() override;
		void update() override;
		void render() override;
	};

}


