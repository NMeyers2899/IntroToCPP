#include <iostream>
#include "Engine.h"
#include "StartScene.h"

bool Engine::m_applicationShouldClose = false;
int Engine::m_sceneCount = 0;
Scene** Engine::m_scenes;
Scene* Engine::m_currentScene;

Engine::Engine()
{
	m_applicationShouldClose = false;
	m_sceneCount = 0;
	m_scenes[m_sceneCount];
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
	StartScene* start = new StartScene();
	Scene* firstScene = new Scene();

	addScene(start);
	addScene(firstScene);

	m_currentScene = m_scenes[0];

	m_currentScene->start();
}

void Engine::update()
{
	m_currentScene->update();
}

void Engine::draw()
{
	m_currentScene->draw();
}

void Engine::end()
{
	m_currentScene->end();
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

