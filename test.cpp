#include <Windows.h>

BOOL RegisterApp(const char* windowID, WNDPROC windowProc) {
	WNDCLASSEXA wc;
	wc.cbSize = sizeof(WNDCLASSEXA);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = windowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandleA(NULL);
	wc.hIcon = (HICON)LoadIconA(NULL, IDI_APPLICATION);
	wc.hCursor = (HCURSOR)LoadCursorA(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = windowID;
	wc.hIconSm = (HICON)LoadImageA(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	return (RegisterClassExA(&wc));
}

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow) {
	HWND hWnd;

	if (!RegisterApp("MyFirstApp", DefWindowProcA)) return FALSE;

	hWnd = CreateWindowA(
		"MyFirstApp",
		"Title",
		WS_OVERLAPPEDWINDOW,
		0, 0, 500, 300,
		NULL, NULL, hCurInst, NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	MessageBoxA(NULL, "Click OK to destroy window", "message", MB_OK);

	DestroyWindow(hWnd);

	return 0;
}
