#include "App.h"
#include <sstream>
#include <iomanip>

Game::Game()
	:
	wnd(800, 600, "Test")
{
}

int Game::Start()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void Game::DoFrame()
{
	Graphics& gfx = wnd.Gfx();

	gfx.ClearBuffer(1, 0, 1);
	wnd.Gfx().DrawTestTriangle();
	gfx.EndFrame();
}