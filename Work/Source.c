#include <Windows.h>
#include <Stdio.h>
int main() {
	
    HANDLE file = CreateFile(L"1.txt", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);//��������� ��� ������
    DWORD size = 100, bytes;
    char* text = calloc(size + 1, 1);//����� ���� ������������ ����������� 
    if (file != INVALID_HANDLE_VALUE) //���� ���� ����
    {
        ReadFile(file, text, size, &bytes, NULL);//������ �����
        CloseHandle(file);//��������� ����� ��� ����� �� ��� ����� ������
    }

    file = CreateFile(L"answer.txt", GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, //���� ��� ����� �������, ���� ���� �����������(������ � ������� ������)
        FILE_ATTRIBUTE_NORMAL, NULL);//��������� ��� ������
    WriteFile(file, text, size, &bytes, NULL);//���������� (size � bytes ��� � ��� ������)

}