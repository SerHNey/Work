//Основной процесс :
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main()
{
    HANDLE hReadPipe, hWritePipe;
    char message[] = "Hello, child process!";
    char buffer[256];
    SECURITY_ATTRIBUTES sa = { sizeof(sa),NULL,TRUE };
    DWORD bytesWritten, bytesRead;
    BOOL success;

    // Создаем анонимный канал
    success = CreatePipe(&hReadPipe, &hWritePipe, &sa, 256);
    if (!success)
    {
        printf("Error creating pipe\n");
        return 1;
    }

    // Создаем дочерний процесс
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.hStdError = hWritePipe;
    si.hStdOutput = hWritePipe;
    si.dwFlags |= STARTF_USESTDHANDLES;

    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));

    success = CreateProcessA(NULL, "..\\x64\\Debug\\child.exe", NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
    if (!success)
    {
        printf("Error creating child process\n");
        return 1;
    }

    while (TRUE) {
        // Читаем из канала
        success = ReadFile(hReadPipe, buffer, sizeof(buffer), &bytesRead, NULL);
        if (!success)
        {
            printf("Error reading from pipe\n");
            return 1;
        }
        buffer[bytesRead] = '\0';
        printf("Received message: %s\n", buffer);
    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main()
{
    //Дочерний процесс :
    HANDLE hReadPipe = GetStdHandle(STD_OUTPUT_HANDLE);


    while (TRUE)
    {
        char message[256];
        DWORD bytesWritten;
        scanf("%s", message);
        WriteFile(hReadPipe, message, strlen(message), &bytesWritten, NULL);
    }
    return 0;


}
