#include <iostream>
#include "Engine.h"
#include "StartScene.h"

bool Engine::m_applicationShouldClose = false;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_sceneCount = 0;
	m_scenes[m_sceneCount];
	m_currentScene = m_scenes[0];
}

Engine::~Engine()
{
	for (int i = 0; i < m_sceneCount; i++)
		delete m_scenes[i];
}

void Engine::addScene(Scene* scene) 
{
	Scene** tempArray = new Scene*[m_sceneCount];

	for (int i = 0; i < m_sceneCount; i++)
		tempArray[i] = m_scenes[i];

	tempArray[m_sceneCount] = scene;

	m_scenes = tempArray;
	m_sceneCount++;
}

void Engine::start()
{
	StartScene start;

	for (int i = 0; i < m_sceneCount; i++)
		m_scenes[i]->start;
}

void Engine::update()
{
	for (int i = 0; i < m_sceneCount; i++)
		m_scenes[i]->update;
}

void Engine::draw()
{
	for (int i = 0; i < m_sceneCount; i++)
		m_scenes[i]->draw;
}

void Engine::end()
{
	for (int i = 0; i < m_sceneCount; i++)
		m_scenes[i]->end;
}

void Engine::run()
{
	start();

	while (!getApplicationShouldClose())
	{
		draw();
		update();
	}

	end();
}

