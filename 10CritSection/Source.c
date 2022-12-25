#include <Windows.h>
#include <Stdio.h>
DWORD WINAPI thread_func(int thread_num);
CRITICAL_SECTION cs;
int count = 0;

DWORD WINAPI thread_func(int thread_num) {

    for (int i = 0; i < 10; i++) {
        EnterCriticalSection(&cs);
        printf("Thread %d: %d\n", thread_num, count);
        count++;
        LeaveCriticalSection(&cs);
        Sleep(100);
    }

    return 0;
}

int main() {
    InitializeCriticalSection(&cs);

    HANDLE thread1 = CreateThread(NULL, 0, thread_func, 1, 0, NULL);
    HANDLE thread2 = CreateThread(NULL, 0, thread_func, 2, 0, NULL);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    DeleteCriticalSection(&cs);

    return 0;
}
