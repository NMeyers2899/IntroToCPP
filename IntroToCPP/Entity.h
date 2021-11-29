#pragma once

class Entity
{
public:
	Entity(char icon, float health, float attack, float defense);

	char getIcon() { return m_icon; }
	float getHealth() { return m_health; }
	float getAttackPower() { return m_attackPower; }
	float getDefense() { return m_defense; }

	float takeDamage(float damageAmount);
	float attack(Entity target);

private: 
	char m_icon;
	float m_health;
	float m_attackPower;
	float m_defense;
};
