#include <iostream>
#include <cstring>
#include "Entity.h"

void printStats(Entity entity)
{
	std::cout << entity.getIcon() << std::endl;
	std::cout << entity.getHealth() << std::endl;
	std::cout << entity.getAttackPower() << std::endl;
	std::cout << entity.getDefense() << std::endl;
}

int main()
{
	Entity wompus = Entity('W', 45, 17, 10);
	Entity unclePhil = Entity('U', 23, 20, 8);

	wompus.attack(unclePhil);
	unclePhil.attack(wompus);

	printStats(wompus);
	printStats(unclePhil);

	return 0;
}