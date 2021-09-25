/***********************************************************************************
	Project  : project01
	FileName : main.c
	Date     : 2021.09.20
	Question : ABC_086_A
	Summary  : シカのAtCoDeerくんは二つの正整数 a,bを見つけました。
               aとbの積が偶数か奇数か判定してください。
***********************************************************************************/
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
