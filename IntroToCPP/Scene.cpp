#include "Scene.h"

Scene::Scene()
{
	m_actorCount = 0;
	m_actors[m_actorCount];
}

bool Scene::getStarted()
{
	m_started = true;
	return m_started;
}

void Scene::addActor(Actor* actor)
{
	Actor** tempArray = new Actor*[m_actorCount];

	for (int i = 0; i < m_actorCount; i++)
		tempArray[i] = m_actors[i];

	tempArray[m_actorCount] = actor;

	m_actors = tempArray;
	m_actorCount++;
}

bool Scene::removeActor(Actor* actor)
{
	bool actorRemoved = false;
	int d = 0;

	Actor** tempArray = new Actor*[m_actorCount - 1];

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

void Scene::start()
{
	getStarted();

	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->start();
}

void Scene::update()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->update();
}

void Scene::draw()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->draw();
}

void Scene::end()
{
	for (int i = 0; i < m_actorCount; i++)
		m_actors[i]->end();
}
