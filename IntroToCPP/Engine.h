#pragma once
#include "Entity.h"

class Engine
{
// Functions
public :
	Engine();

	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

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
