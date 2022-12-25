#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>
BOOL work = TRUE;
void* secondsmer() {
    int start, end;
    int ms = 0;
    int ns = 0;
    int sec = 0, min = 0, hrs = 0;
    start = clock();
    while (work)
    {
        end = clock();
        ns = end - start;
        ms = ns / 10;
        if (ms > 100)
        {
            sec = sec + 1;
            ms = ms - 100;
            start = end;
        }
        if (sec > 59)
        {
            min = min + 1;
            sec = 0;
        }
        if (min > 59)
        {
            hrs = hrs + 1;
            min = 0;
        }
        printf("%d:%d:%d.%d\n", hrs, min, sec, ms);
    }
}

int main()
{
    system("chcp 1251 >null");
    DWORD choose = -1;
    HANDLE hTread = NULL;
    printf("\n1 - секундомер\n0 - Остановить\n");
    while (1)
    {
        scanf_s("%d", &choose);
        if (choose == 1) {
            if (hTread == NULL) {
                hTread = CreateThread(NULL, 0, secondsmer, 0, NULL, NULL);
                work = TRUE;
            }
        }
        else
        {
            if (hTread != 0) {
                work = FALSE;
                CloseHandle(hTread);
                hTread = NULL;
            }

        }
    }
}