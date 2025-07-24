#include <windows.h>
#include <stdlib.h>  // For rand()
#include <time.h>    // For seeding rand()
#include <string.h>  // For strcpy()

// Function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void OnCreate(HWND);
void OnDestroy(HWND);
void OnLButtonDown(HWND, int, int);
void OnRButtonDown(HWND, int, int);

COLORREF col; // Current text color
int r, g, b;  // RGB components
HFONT hFont;  // Font handle

// Initialization function to register and create the window
BOOL initInstance(HINSTANCE hInstance, int nCmdShow, LPCSTR className) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = className;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClass(&wc))
        return FALSE;

    HWND hwnd = CreateWindow(className, "Click to Draw Text",
                             WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             600, 400, NULL, NULL, hInstance, NULL);

    if (!hwnd)
        return FALSE;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    return TRUE;
}

// Entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    MSG m;
    srand((unsigned)time(NULL));  // Seed random generator

    r = 255; g = 0; b = 0;
    col = RGB(r, g, b); // Initial red

    if (!initInstance(hInstance, nCmdShow, "HelloClass"))
        return 0;

    while (GetMessage(&m, NULL, 0, 0)) {
        TranslateMessage(&m);
        DispatchMessage(&m);
    }

    return (int)m.wParam;
}

// Main window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
            OnCreate(hwnd);
            break;
        case WM_DESTROY:
            OnDestroy(hwnd);
            break;
        case WM_LBUTTONDOWN:
            OnLButtonDown(hwnd, LOWORD(lParam), HIWORD(lParam));
            break;
        case WM_RBUTTONDOWN:
            OnRButtonDown(hwnd, LOWORD(lParam), HIWORD(lParam));
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

// Create font
void OnCreate(HWND hwnd) {
    LOGFONT lf = {0};
    strcpy(lf.lfFaceName, "Arial");
    lf.lfHeight = -24; // Negative for logical height (in pixels)
    hFont = CreateFontIndirect(&lf);
}

// Cleanup
void OnDestroy(HWND hwnd) {
    DeleteObject(hFont);
    PostQuitMessage(0);
}

// Left click draws text
void OnLButtonDown(HWND hwnd, int x, int y) {
    HDC hdc = GetDC(hwnd);
    HGDIOBJ oldFont = SelectObject(hdc, hFont);
    SetTextColor(hdc, col);
    SetBkMode(hdc, TRANSPARENT);  // Transparent background
    TextOut(hdc, x, y, "Hello, World!", 13);
    SelectObject(hdc, oldFont);
    ReleaseDC(hwnd, hdc);
}

// Right click changes text color
void OnRButtonDown(HWND hwnd, int x, int y) {
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
    col = RGB(r, g, b);
}
