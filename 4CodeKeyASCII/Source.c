#include <Windows.h>
#include <Stdio.h>
LRESULT CALLBACK LogMouse(int iCode, WPARAM wParam, LPARAM lParam);

int main() {
	

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	HHOOK hHOOK = SetWindowsHookExW(WH_MOUSE_LL, LogMouse, NULL, NULL);
}

LRESULT CALLBACK LogMouse(int iCode, WPARAM wParam, LPARAM lParam) {
	KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
	int iKey = MapVirtualKeyA(p->vkCode, NULL);
	WCHAR procID[256];
	swprintf_s(procID, 256, L"%d", iKey);
	MessageBox(NULL, procID, L"Key Pressed", MB_OK);
}