#pragma once
#include "Entity.h"

class Engine
{
// Functions
public :
	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

// Variables
private :
	static bool m_applicationShouldClose;
	int m_entityCount;
	Entity m_entities[];

// Functions
private :
	void start();
	void update();
	void draw();
	void end();
};
