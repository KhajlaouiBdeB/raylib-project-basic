#include "GameTest.h"
#include <raylib.h>


namespace core
{
	GameTest::GameTest() : GameBase()
	{
		InitWindow(720, 480, "Game Test");
		SetTraceLogLevel(LOG_DEBUG);
		SetTargetFPS(60);

		size = 50.0f;
		ground = 480.0f - size;
		x = 360.0f - size / 2.0f; 
		y = ground;
		velocityX = 0.0f;
		velocityY = 0.0f;
		onGround = true;
	}

	GameTest::~GameTest()
	{
		CloseWindow();
	}

	void GameTest::inputHandler()
	{
		if (IsKeyDown(KEY_RIGHT)) velocityX = velocityX + 25.0f;
		if (IsKeyDown(KEY_LEFT))  velocityX = velocityX - 25.0f;

		if (IsKeyPressed(KEY_SPACE) && onGround)
		{
			velocityY = -550.0f; 
			onGround = false;
		}
	}

	void GameTest::update()
	{
		_tree.tick();

		float dt = GetFrameTime();

		velocityY = velocityY + 1200.0f * dt;
		velocityX = velocityX * 0.98f;

		if (velocityX > 600.0f)  velocityX = 600.0f;
		if (velocityX < -600.0f) velocityX = -600.0f;

		x = x + velocityX * dt;
		y = y + velocityY * dt;

		if (y >= ground)
		{
			y = ground;
			velocityY = 0.0f;
			onGround = true;
		}

		if (x <= 0.0f)
		{
			x = 0.0f;
			velocityX = -velocityX * 0.5f;
		}

		if (x + size >= 720.0f)
		{
			x = 720.0f - size;
			velocityX = -velocityX * 0.5f;
		}
	}

	void GameTest::render()
	{
		DrawRectangle((int)x, (int)y, (int)size, (int)size, BLUE);

		DrawRectangle((int)(x + 12), (int)(y + 14), 8, 8, WHITE);
		DrawRectangle((int)(x + 30), (int)(y + 14), 8, 8, WHITE);

		DrawRectangle((int)(x + 14), (int)(y + 32), 22, 6, WHITE);
	}
}