#pragma once

namespace core
{

	class GameBase
	{
	public:

		virtual ~GameBase();
		//TODO
		//Starting point
		void run();
		//Handle input
		virtual void inputHandler() = 0;
		//Update
		virtual void update() = 0;
		//Render
		virtual void render() = 0;

	protected:
		GameBase();


	};

}

