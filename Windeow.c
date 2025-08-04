#include <windows.h>
#include <resource.h>  // Assuming you have resources defined here like IDM_ABOUT, IDM_EXIT, etc.

// Forward declaration of About dialog procedure
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

// Global instance handle (assumed to be declared elsewhere)
extern HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    int wmid, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
    case WM_COMMAND:
        wmid = LOWORD(wParam);   // ? Corrected syntax from LOWORD{wParam}
        wmEvent = HIWORD(wParam); // ? Corrected syntax from HlWORD{wParam}

        switch (wmid) {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); // ? Fixed spelling of MAKEINTRESOURCE
            break;

        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam); // ? Fixed incorrect comma usage
        }
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        // Drawing code can go here if needed
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

