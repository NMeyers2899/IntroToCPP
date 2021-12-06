#include "ActorArray.h"

void ActorArray::addActor(Actor* actor)
{
	Actor** tempArray = new Actor * [m_actorCount];

	for (int i = 0; i < m_actorCount; i++)
		tempArray[i] = m_actors[i];

	tempArray[m_actorCount] = actor;

	m_actors = tempArray;
	m_actorCount++;
}

bool ActorArray::removeActor(Actor* actor)
{
	bool actorRemoved = false;
	int d = 0;

	Actor** tempArray = new Actor * [m_actorCount - 1];

	for (int i = 0; i < m_actorCount; i++)
	{
		if (actor == m_actors[i] && !actorRemoved)
		{
			d++;
			actorRemoved = true;
		}

		tempArray[d] = m_actors[i];
		d++;
	}

	m_actors = tempArray;
	m_actorCount--;

	return actorRemoved;
}

bool ActorArray::removeActor(int index)
{
	bool actorRemoved = false;
	int d = 0;

	Actor** tempArray = new Actor * [m_actorCount - 1];

	for (int i = 0; i < m_actorCount; i++)
	{
		if (index == i && !actorRemoved)
		{
			d++;
			actorRemoved = true;
		}

		tempArray[d] = m_actors[i];
		d++;
	}

	m_actors = tempArray;
	m_actorCount--;

	return actorRemoved;
}

Actor* ActorArray::getActor(int index)
{
	if(index < 0 || index >= m_actorCount)
		return nullptr;

	return m_actors[index];
}

bool ActorArray::contains(Actor* actor)
{
	for (int i = 0; i < m_actorCount; i++)
	{
		if (m_actors[i] == actor)
			return true;
	}

	return false;
}
