//	2021.09.20

#include <stdio.h>

int main() 
{
	int a = 0, b = 0, sum = 0;
	scanf("%d %d", &a, &b);
	sum = a * b;
	if (sum % 2 == 0) {
		printf("Even\n");
	} else {
		printf("Odd\n");
	}
	return 0;
}
