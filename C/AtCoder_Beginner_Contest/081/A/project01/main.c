/***********************************************************************************
	Project  : project01
	FileName : main.c
	Date     : 2021.09.20
	Question : ABC_081_A
	Summary  : シカのAtCoDeerくんは二つの正整数 a,bを見つけました。
               aとbの積が偶数か奇数か判定してください。
***********************************************************************************/
#include <stdio.h>

int main()
{
	int i, temp, num = 0;
	
	scanf("%d", &temp);
	for (i = 0; i < 3; i++) {
		if (temp % 10 != 0) {
			num++;
		}
		temp /= 10;
	}
	printf("%d\n", num);
	return 0;
}