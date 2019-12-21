#pragma once
#include "Window.h"
#include "Timer.h"

class Game
{
public:
	Game();
	// master frame, message loop
	int Start();
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
};

