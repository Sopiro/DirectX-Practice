#include "App.h"
#include <sstream>
#include <iomanip>

Game::Game()
	:
	wnd(800, 600, "D3D exploration")
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
	gfx.DrawTestTriangle(
		timer.Peek(),
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f
	);
	gfx.EndFrame();
}