#include <iostream>
#include "Entity.h"

Entity::Entity()
{
	m_health = 0;
	m_attackPower = 0;
	m_defense = 0;
}

Entity::Entity(float health, float attackPower, float defense)
{
	m_health = health;
	m_attackPower = attackPower;
	m_defense = defense;
}

float Entity::takeDamage(float damageAmount)
{
	// Subtracts the damage being dealt by the entity's defense.
	float damageTaken = damageAmount - getDefense();

	// If the damage being taken is less than zero...
	if (damageTaken < 0)
		// ...it changes the damage being taken to zero.
		damageTaken = 0;

	// Subtracts the damage from the entity's health.
	m_health -= damageTaken;

	// If the entity's health is less than zero...
	if (m_health < 0)
		// ...it sets the entity's health to zero.
		m_health = 0;
	
	return damageTaken;
}

float Entity::attack(Entity* target)
{
	return target -> takeDamage(m_attackPower);
}

void Entity::printStats()
{
	std::cout << "Health : " << getHealth() << std::endl;
	std::cout << "Attack Power : " << getAttackPower() << std::endl;
	std::cout << "Defense : " << getDefense() << std::endl;
}
