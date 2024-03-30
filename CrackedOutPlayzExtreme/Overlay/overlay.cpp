#include "overlay.h"

Overlay::Overlay() : hwnd(NULL), screenWidth(GetSystemMetrics(SM_CXSCREEN)), screenHeight(GetSystemMetrics(SM_CYSCREEN)), gdiToken(NULL) {}
Overlay::~Overlay() {}

void Overlay::CreateOverlay(int nCmdShow) {
    WNDCLASSW wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = L"OverlayClass";
    
    RegisterClassW(&wc);

    hwnd = CreateWindowEx(
        WS_EX_COMPOSITED | WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TRANSPARENT, //WS_EX_NOACTIVATE = not in taskbar
        L"OverlayClass",
        L"Overlay Window",
        WS_POPUP, //for no program border
        0, 0, screenWidth, screenHeight,
        NULL,  
        NULL,
        wc.hInstance,
        NULL
    );

    HRGN GGG = CreateRectRgn(0, 0, screenWidth, screenHeight);
    InvertRgn(GetDC(hwnd), GGG);
    SetWindowRgn(hwnd, GGG, false);

    COLORREF RRR = RGB(0, 0, 0);
    SetLayeredWindowAttributes(hwnd, RRR, (BYTE)0, LWA_COLORKEY);

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiToken, &gdiplusStartupInput, NULL);


    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

}

void Overlay::DestroyOverlay() {
	DestroyWindow(hwnd);
	hwnd = NULL;
    Gdiplus::GdiplusShutdown(gdiToken);
}

LRESULT CALLBACK Overlay::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            //draw here
            //Drawing::Draw_Text(hdc, L"OMG I LOVE CHEATZ", 100, 100, Gdiplus::Color(255, 255, 100, 0));
            //Drawing::DrawBoundingBox(hdc, 100, 100, 200, 400, Gdiplus::Color(255, 0, 0, 255), 2);
            //Drawing::DrawLine(hdc, 500, 500, 800, 800, Gdiplus::Color(255, 0, 255, 100), 2);

            EndPaint(hWnd, &ps);
        }
		break;
    case WM_ERASEBKGND:
        RECT rect;
        GetClientRect(hWnd, &rect);
        FillRect((HDC)wParam, &rect, CreateSolidBrush(RGB(0, 0, 0)));
        break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}