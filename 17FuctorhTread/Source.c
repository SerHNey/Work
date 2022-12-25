#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
int c = 0;

int FacKU(int n) {
	if (n == 0)
		return 1;
	if (n < 1)
		return 0;
	int a = 1;
	for (size_t i = 1; i <= n; i++)
	{
		a *= i;
	}
	return c = a;
}

main() {
	HANDLE hThread;
	while (1) {
		char str[256];
		scanf("%s", str);
		int n = atoi(str);
		if (n != NULL) {
			hThread = CreateThread(NULL, 0, FacKU, n, NULL, NULL);
			WaitForSingleObject(hThread, INFINITE);
			printf("%d\n", c);
		}
	}
}
