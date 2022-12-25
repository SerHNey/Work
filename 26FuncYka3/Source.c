#include <Stdio.h>

int Sum(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}


int SorD(int(*f)(int, int), int a, int b) {
	return(f(a, b));
}

int main() {
	printf("%d\n", SorD(Sub, 5, 2));
	printf("%d\n", SorD(Sum, 5, 2));
}
