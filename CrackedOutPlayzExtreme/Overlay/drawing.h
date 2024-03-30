#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include <cwchar>

namespace Drawing {
	void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, Gdiplus::Color color, int lineSize);
	void DrawBoundingBox(HDC hdc, int x, int y, int width, int height, Gdiplus::Color color, int boxSize);
	void DrawCircle(HDC hdc, int x, int y, int radius, Gdiplus::Color color, int circleSize);
	void Draw_Text(HDC hdc, const WCHAR* string, int x, int y, Gdiplus::Color color);
}