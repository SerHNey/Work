#include <Windows.h>
#include <Stdio.h>
int main() {
	LPWSTR text = NULL;
	OpenClipboard(NULL);
	HANDLE CBtext = GetClipboardData(CF_UNICODETEXT);
	text = (LPWSTR)GlobalLock(CBtext);
	MessageBox(NULL, text, L"Оповещение", MB_OK);
	GlobalUnlock(CBtext);
	//EmptyClipboard();
	CloseClipboard();
	return 0;
}

