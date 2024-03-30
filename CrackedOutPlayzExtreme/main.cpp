#include "Overlay/overlay.h"
#include <chrono>
#include <thread>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow) {
	Overlay newOverlay;
	newOverlay.CreateOverlay(nCmdShow);

	return 0;
}