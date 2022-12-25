#include <stdio.h>
#include <Windows.h>
//1 процесс:
char* CBOuput()
{
	LPWSTR text = NULL;
	OpenClipboard(NULL);
	HANDLE CBtext = GetClipboardData(CF_UNICODETEXT);
	text = (LPWSTR)GlobalLock(CBtext);
	GlobalUnlock(CBtext);
	EmptyClipboard();
	CloseClipboard();
	if (text == NULL)
		return NULL;
	char* outtext = calloc(2048, 1);
	wcstombs(outtext, text, 2048);
	return outtext;
}


int main() {
	while (1)
	{
		Sleep(1000);
		char* text = CBOuput();
		if (text != NULL)
			printf("%s\n", text);
	}
}
//2 процесс:
void CBInput(LPWSTR text)
{
	HANDLE hMem = GlobalAlloc(GMEM_MOVEABLE, (wcslen(text) + 1) * sizeof(LPWSTR));
	memcpy(GlobalLock(hMem), text, (wcslen(text) + 1) * sizeof(LPWSTR));
	GlobalUnlock(hMem);
	OpenClipboard(NULL);
	//EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
}
wchar_t* convertCharArrayToLPCWSTR(char* charArray)
{
	wchar_t* wString[512];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

int main(int argc, char* argv[]) {
	char str[256];
	while (1)
	{
		scanf("%s", str);
		CBInput(convertCharArrayToLPCWSTR(str));
	}
};
