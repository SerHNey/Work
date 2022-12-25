#include <Windows.h>
#include <Stdio.h>
int main() {
	
    HANDLE file = CreateFile(L"1.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);//открываем для чтения
    DWORD size = 100, bytes;
    char* text = calloc(size + 1, 1);//буфер куда записывается прочитанное 
    if (file != INVALID_HANDLE_VALUE) //если файл есть
    {
        ReadFile(file, text, size, &bytes, NULL);//читаем ебать
        CloseHandle(file);//закрываем нахуй ибо нахуй он нам нужен теперь
    }

    file = CreateFile(L"answer.txt", GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, //если нет файла создаст, если есть перезапишет(удалит и создаст заново)
        FILE_ATTRIBUTE_NORMAL, NULL);//открываем для записи
    WriteFile(file, text, size, &bytes, NULL);//записываем (size и bytes как и при чтении)

}