#include "Engine.h"

void Engine::start()
{

}

void Engine::update()
{

}

void Engine::draw()
{

}

void Engine::end()
{

}

void Engine::run()
{
	start();

	while (!getApplicationShouldClose())
	{
		update();
		draw();
	}

	end();
}
