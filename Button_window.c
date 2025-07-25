#include <windows.h>

HWND hButton = NULL;

// Window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                MessageBox(hwnd, "Button clicked!", "Info", MB_OK);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    // Register window class
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWinClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    // Create main window
    HWND hwnd = CreateWindow("MyWinClass", "Button Window",
                             WS_OVERLAPPEDWINDOW, 100, 100, 400, 300,
                             NULL, NULL, hInstance, NULL);

    // Create a standard push button
    hButton = CreateWindow(
        "BUTTON", "Hit me",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        20, 20, 150, 100,
        hwnd, (HMENU)1, hInstance, NULL);

    // Handle command-line argument
    int temp = atoi(lpCmdLine);
    switch (temp) {
        case 2:
            ShowWindow(hwnd, SW_SHOWMINIMIZED);
            break;
        case 3:
            ShowWindow(hwnd, SW_SHOWMAXIMIZED);
            break;
        default:
            ShowWindow(hwnd, SW_SHOWNORMAL);
            break;
    }

    UpdateWindow(hwnd);
    MessageBox(0, "Wait....", "Wait", 0);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

