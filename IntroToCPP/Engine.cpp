#include "Engine.h"

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_entityCount = 0;
	m_currentFighterIndex = 0;
}

void Engine::start()
{
	Entity wompus = Entity('W', 130002000, 5780002, -15000);
	Entity redactedLittleSkeleton = Entity('r', 440000 - 44000, 45500 - 40, 0);
	Entity unclePhil = Entity('U', 1, 0, 6900055);

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
