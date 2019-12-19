#include <Windows.h>
#include <string>
#include "Window.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	Window wnd(640, 480, "Test");

	// Run the message loop.
	MSG msg;
	BOOL gResult;

	while (gResult = (GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
		return -1;
	else
		return msg.wParam;

	return 0;
}