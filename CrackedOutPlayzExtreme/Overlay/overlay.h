#pragma once
#include "drawing.h"

class Overlay
{
public:
	Overlay();
	~Overlay();

	void CreateOverlay(int nCmdShow);
	void DestroyOverlay();

private:
	HWND hwnd;
	int screenWidth;
	int screenHeight;
	ULONG_PTR gdiToken;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};