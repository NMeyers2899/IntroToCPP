#pragma once
#include "Entity.h"
#include "Scene.h"

class Engine
{
// Functions
public :
	Engine();
	~Engine();

	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

	void addScene(Scene* scene);
	static Scene* getCurrentScene();
	static void setCurrentScene(int index);

// Variables
private :
	static bool m_applicationShouldClose;
	
	Entity m_entities[3];
	Entity* m_currentFighter1;
	Entity* m_currentFighter2;

	int m_entityCount;
	int m_currentFighterIndex;

// Functions
private :
	void start();
	void update();
	void draw();
	void end();
};
