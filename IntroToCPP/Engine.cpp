#include <iostream>
#include "Engine.h"

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}

Engine::~Engine()
{
	delete m_currentFighter1;
	delete m_currentFighter2;
}

void Engine::start()
{
	// Initalizing the stats for entities.
	Entity wompus = Entity('W', 3, 2, 1);
	Entity redactedLittleSkeleton = Entity('r', 2, 1, 1);
	Entity unclePhil = Entity('U', 2, 2, 1);

	m_entities[0] = wompus;
	m_entities[1] = redactedLittleSkeleton;
	m_entities[2] = unclePhil;
	m_entityCount = 3;

	m_currentFighter1 = &m_entities[0];
	m_currentFighter2 = &m_entities[1];
	m_currentFighterIndex = 2;
}

void Engine::update()
{
	// If the first monster's health is less than or equal to zero...
	if (m_currentFighter1->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		// ...replace that fighter.
		m_currentFighter1 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	// If the second monster's health is less than or equal to zero...
	if (m_currentFighter2->getHealth() <= 0 && m_currentFighterIndex < m_entityCount)
	{
		// ...replace that fighter.
		m_currentFighter2 = &m_entities[m_currentFighterIndex];
		m_currentFighterIndex++;
	}

	if ((m_currentFighter1->getHealth() <= 0 || m_currentFighter2->getHealth() <= 0)
		&& m_currentFighterIndex <= m_entityCount)
	{
		m_applicationShouldClose = true;
		return;
	}

	// Both fighters attack each other, assuming they have enough health to continue fighting.
	m_currentFighter1 -> attack(m_currentFighter2);
	m_currentFighter2 -> attack(m_currentFighter1);
}

void Engine::draw()
{
	m_currentFighter1->printStats();
	m_currentFighter2->printStats();
	system("pause");
	system("cls");
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
