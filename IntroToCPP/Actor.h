#pragma once

class Actor
{
public:
	Actor() { m_name = ""; }
	Actor(const char* name) { m_name = name; }

	bool getStarted();

	virtual void start() { m_started = true; }
	virtual void update() {};
	virtual void draw() {};
	virtual void end() {};

private:
	const char* m_name;
	bool m_started = false;
};
