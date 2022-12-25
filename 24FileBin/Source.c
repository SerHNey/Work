#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main()
{
    FILE* file = NULL;
	int number;

	file = fopen("bin.bin", "wb");
	if (file == NULL) {
		printf("Error opening file");
	}

	scanf("%d", &number);
	fwrite(&number, sizeof(int), 1, file);

	fclose(file);

	file = fopen("bin.bin", "rb");
		if (file == NULL) {
	printf("Error opening file");
		}

	fread(&number, sizeof(int), 1, file);
	printf("%d", number);

	fclose(file);

}

