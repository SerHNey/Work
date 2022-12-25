#include <stdio.h>
#include <Windows.h>

int main() {
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	char* koef = "zzz";
	char path2[256];
	char* path = "..\\x64\\Debug\\child.exe";
	sprintf(path2, "%s \"%s\"", path, koef);
	CreateProcessA(path, koef, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	CreateProcessA(NULL, path2, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
}
