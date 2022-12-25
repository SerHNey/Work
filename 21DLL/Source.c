#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

typedef struct coordinats {
	COORD point1;
	COORD point2;
}cord;
__declspec(dllimport) double getSize(cord* cord);

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:

		break;

	case DLL_THREAD_ATTACH:

		break;

	case DLL_THREAD_DETACH:

		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


double getSize(cord* cord)
{
	double d = sqrt((pow(cord->point2.X - cord->point1.X, 2) + pow(cord->point2.Y - cord->point1.Y, 2)), 2);
	return d;
}

//Код для основной программы
#define PATH L"DLLCode.dll"
typedef double(_cdecl* getSize)(struct cord*);

typedef struct coordinats {
	COORD point1;
	COORD point2;
}cord;


int main()
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	getSize getSqize = (getSize)GetProcAddress(hMyDLL, "getSize");
	cord* cord = malloc(sizeof(cord));
	cord->point1.X = 2;
	cord->point1.Y = 1;
	cord->point2.X = 6;
	cord->point2.Y = 4;
	double result = getSqize(cord);
	FreeLibrary(hMyDLL);
	return 0;
}

