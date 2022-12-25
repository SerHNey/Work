#include <stdio.h>
#include <Windows.h>

int main() {
	OPENFILENAME ofn;
	char szFile[256];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	GetOpenFileName(&ofn);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess(NULL, szFile, NULL, NULL, NULL, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	return 0;
}
