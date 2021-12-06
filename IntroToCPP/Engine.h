#pragma once
#include "Entity.h"
#include "Scene.h"

class Engine
{
public :
	Engine();
	~Engine();

	void run();

	static bool getApplicationShouldClose() { return m_applicationShouldClose; }
	static void setApplicationShouldClose(bool value) { m_applicationShouldClose = value; }

	void addScene(Scene* scene);
	static Scene* getCurrentScene() { return m_currentScene; }
	static void setCurrentScene(int index) { m_currentScene = m_scenes[index]; }

private :
	static bool m_applicationShouldClose;

	static Scene** m_scenes;
	static Scene* m_currentScene;
	static int m_sceneCount;

	void start();
	void update();
	void draw();
	void end();
};
