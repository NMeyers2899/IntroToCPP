#include <iostream>
#include "StartScene.h"
#include "Engine.h"

void StartScene::draw()
{
	system("cls");
	std::cout << "Welcome to your Odd Adventure! \nWhat would you like to do? (Please enter the number)";
	std::cout << "\n1. Start Game \n2. End Game" << std::endl;
}

void StartScene::update()
{
	int playerChoice = 0;
	std::cin >> playerChoice;

	if (playerChoice == 1)
		Engine::setCurrentScene(1);
	else if (playerChoice == 2)
		Engine::setApplicationShouldClose(true);
}
