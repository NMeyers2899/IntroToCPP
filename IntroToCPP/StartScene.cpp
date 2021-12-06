#include <iostream>
#include "StartScene.h"

void StartScene::draw()
{
	std::cout << "Welcome to your Odd Adventure! \nWhat would you like to do? (Please enter a number) \n1. Start Game \n 2. End Game" << std::endl;
}

void StartScene::update()
{
	bool choiceMade = false;
	int playerChoice = 0;

	while (!choiceMade)
	{
		std::cin >> playerChoice;
		if (playerChoice == 1)
			Engine::setCurrentScene(1);
	}
}
