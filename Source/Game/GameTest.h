#pragma once
#include "../Core/GameBase.h"

#include "BehaviorThree/Core/BehaviourTree.h"


namespace core
{
	class GameTest : public GameBase
	{
		BehaviourTree::BehaviourTree _tree;
	public:
		GameTest();
		~GameTest() override;
		void inputHandler() override;
		void update() override;
		void render() override;
	private:
		float x;
		float y;
		float velocityX;
		float velocityY;
		float size;
		float ground;
		bool onGround;
	};
}