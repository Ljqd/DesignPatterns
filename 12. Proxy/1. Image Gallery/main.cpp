#include <Windows.h>
#include <gdiplus.h>
#pragma comment(lib,"gdiplus.lib")


#include <iostream>
#include <string>
#include <vector>

#include "src/ImageGallery.h"


using namespace Gdiplus;

std::vector<std::string> getFiles();
void initGallery(ImageGallery* ptr);

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND getHWND(HINSTANCE hInstance);

// replace standart main()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HWND hwnd = getHWND(hInstance);
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    GdiplusShutdown(gdiplusToken);
    return (int)msg.wParam;
}

HWND getHWND(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"WindowClass";
    wcex.hIconSm = NULL;
    RegisterClassEx(&wcex);

    ImageGallery* gallery = new ImageGallery(); // just declare to get address
    HWND hwnd = CreateWindow(L"WindowClass", L"Simple Image Viewer", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, NULL, NULL, hInstance, gallery);
    return hwnd;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;
    HDC memDC;

    ImageGallery* gallery = nullptr;

    switch (message) {
    case WM_CREATE:
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT*)lParam)->lpCreateParams);
        break;
    case WM_PAINT:

        // ---------------- Init gallerya
        gallery = (ImageGallery*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        if (!gallery->is())
            initGallery(gallery);

        // ---------------- get HDC pointers
        hdc = BeginPaint(hwnd, &ps);
        memDC = CreateCompatibleDC(hdc);

        // ---------------- gallery draw
        gallery->drawNext(hdc, memDC);

        // ---------------- end paint
        DeleteDC(memDC);
        ReleaseDC(hwnd, hdc);
        EndPaint(hwnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

std::vector<std::string> getFiles()
{
    std::string folder = "./resources/";
    std::vector<std::string> files(10);

    for (int i = 0; i < 10; i++)
    {
        std::string filePath = folder + "image" + std::to_string(i) + ".jpeg";
        files[i] = filePath;
    }
    return files;
}

void initGallery(ImageGallery* ptr)
{
    std::vector<std::string> files = getFiles();
    ptr->init(files);
}