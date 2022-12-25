#include <Windows.h>
#include <Stdio.h>
int main() {
	LPWSTR text = L"DAWD123";
	HANDLE hMem = GlobalAlloc(GMEM_MOVEABLE, (wcslen(text) + 1) * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), text, (wcslen(text) + 1) * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	return 0;
}
