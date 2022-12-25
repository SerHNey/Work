#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>
#include <Windows.h>

typedef struct LOS {
	int arg;
	int min;
	int max;
	struct LOS* next;

}LOS;

void GetMinMax(LOS* los) {
	LOS* head = los;
	int max;
	int min = los->arg;
	while (los) {
		if (los->next != NULL) {
			int n = los->next->arg;
			if (los->arg > n)
				max = los->arg;
		}

		if (min > los->arg)
			min = los->arg;
		los = los->next;
	}
	los = head;
	los->min = min;
	los->max = max;
}

void WriteLOS(LOS* los) {
	LOS* head = los;
	while (los)
	{
		printf("значение - %d\n", los->arg);
		los = los->next;
	}
	los = head;
	printf("min - %d; max - %d", los->min, los->max);
}

LOS* createLOS(int count) {
	LOS* los = calloc(1, sizeof(LOS));
	los->arg = rand();
	los->next = NULL;
	LOS* headCopy, * next;
	headCopy = los;
	for (size_t i = 0; i < count - 1; i++)
	{
		next = calloc(1, sizeof(LOS));
		next->arg = rand();
		headCopy->next = next;
		headCopy = next;
	}
	headCopy->next = NULL;
	return los;
}

main() {
	LOS* los = createLOS(5);
	GetMinMax(los);
	WriteLOS(los);
}
