//��� �������
// ��������� �� 2 �������

#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>
#include <Windows.h>
int main()
{
	system("chcp 1251");
	BOOL flag_awser = TRUE;
	char message[100];
	DWORD read_buffer = 100;
	DWORD actual_read;
	DWORD actual_write;
	LPWSTR buffer = (CHAR*)calloc(read_buffer, sizeof(char));
	HANDLE hNamePipe;
	LPSTR pipeName = L"\\\\.\\pipe\\MyPipe";
	BOOL SuccessRead;
	BOOL isSuccess;
	DWORD dwMode = PIPE_READMODE_MESSAGE;
	while (1)
	{
		hNamePipe = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		isSuccess = SetNamedPipeHandleState(hNamePipe, &dwMode, NULL, NULL);
		if (!isSuccess) {
			printf("\n������ �� ��������\n");
			flag_awser = TRUE;
		}
		else
		{
			if (flag_awser) {
				printf("������� ��������� ��� �������: \n");
				gets(message);
				buffer = &message;
				WriteFile(hNamePipe, buffer, read_buffer, &actual_write, NULL);
				flag_awser = FALSE;
			}
			SuccessRead = ReadFile(hNamePipe, buffer, 100, &actual_read, NULL);
			if (SuccessRead) {
				printf("\n������ �����: ");
				printf(buffer);
				printf("\n");
				flag_awser = TRUE;
				if (buffer == NULL)
					printf("�����");
			}
		}
		Sleep(100);
		CloseHandle(hNamePipe);
	}
}


//��� �������
#include <Stdio.h>
#include <Windows.h>
int main()
{
	system("chcp 1251");
	HANDLE hNamePipe;
	LPSTR pipeName = L"\\\\.\\pipe\\MyPipe";
	DWORD read_buffer = 100;
	LPWSTR buffer = calloc(read_buffer, sizeof(char));
	char message[100];
	DWORD actual_read;
	BOOL Connected;
	BOOL SuccessRead;
	while (1)
	{
		hNamePipe = CreateNamedPipe(
			pipeName,
			PIPE_ACCESS_DUPLEX,
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
			PIPE_UNLIMITED_INSTANCES,
			512,
			512,
			INFINITE,
			NULL);
		Connected = ConnectNamedPipe(hNamePipe, NULL);
		if (Connected) {
			printf("\n������ �����������\n");
			SuccessRead = ReadFile(hNamePipe, buffer, read_buffer, &actual_read, NULL);
			if (SuccessRead) {
				printf("\n������ �����: ");
				printf(buffer);
				printf("\n");
				printf("\n������� ��������� ��� �������: ");
				gets(message);
				buffer = &message;
				WriteFile(hNamePipe, buffer, read_buffer, &actual_read, NULL);
			}
		}
		else
		{
			printf("\n������ ���������� �� �������");
		}
		CloseHandle(hNamePipe);
	}
}
