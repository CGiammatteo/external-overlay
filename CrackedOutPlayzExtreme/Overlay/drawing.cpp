#include "drawing.h"

void Drawing::DrawLine(HDC hdc, int x1, int y1, int x2, int y2, Gdiplus::Color color, int lineSize)
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::Pen pen(color, lineSize);

	Gdiplus::Point p1(x1, y1);
	Gdiplus::Point p2(x2, y2);

	graphics.DrawLine(&pen, p1, p2);

	graphics.~Graphics();
}

void Drawing::DrawBoundingBox(HDC hdc, int x, int y, int width, int height, Gdiplus::Color color, int boxSize)
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::Pen pen(color, boxSize);
	Gdiplus::RectF rectangle(x, y, width, height);

	graphics.DrawRectangle(&pen, rectangle);

	pen.~Pen();
	graphics.~Graphics();
}

void Drawing::DrawCircle(HDC hdc, int x, int y, int radius, Gdiplus::Color color, int circleSize)
{
}

void Drawing::Draw_Text(HDC hdc, const WCHAR* string, int x, int y, Gdiplus::Color color)
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::Font myFont(L"Arial", 16, Gdiplus::FontStyleBold);
	Gdiplus::PointF origin(x, y);
	Gdiplus::SolidBrush textBrush(color);

	graphics.DrawString(string, wcslen(string), &myFont, origin, &textBrush);

	graphics.~Graphics();
}