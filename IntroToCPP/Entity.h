#pragma once
#include "Actor.h"

class Entity : public Actor
{
public:
	Entity();
	Entity(const char* name, float health, float attack, float defense);

	float getHealth() { return m_health; }
	float getAttackPower() { return m_attackPower; }
	float getDefense() { return m_defense; }

	float takeDamage(float damageAmount);
	float attack(Entity* target);

	void printStats();

private: 
	float m_health;
	float m_attackPower;
	float m_defense;
};
