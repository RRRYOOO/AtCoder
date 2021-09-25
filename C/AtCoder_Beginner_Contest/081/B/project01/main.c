/***********************************************************************************
	Project  : project01
	FileName : main.c
	Date     : 2021.09.20
	Question : ABC_081_B
	Summary  : 黒板に N 個の正の整数 A1,...,AN が書かれています．
               すぬけ君は，黒板に書かれている整数がすべて偶数であるとき，次の操作
               を行うことができます．
               黒板に書かれている整数すべてを，2 で割ったものに置き換える．
               すぬけ君は最大で何回操作を行うことができるかを求めてください．
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(int*, int);
void splite(int*, int);

int main() {
	int i = 0, count, *num, cycle = 0;
	char *tmp1, *tmp2, *tmp3;

	tmp1 = (char*)malloc(sizeof(char) * 11);
	fgets(tmp1, sizeof(tmp1), stdin);
	count = atoi(tmp1);
	free(tmp1);

	num = (int*)malloc(sizeof(int) * count);
	tmp2 = (char*)malloc(sizeof(char) * 11 * count);
	tmp3 = (char*)malloc(sizeof(char) * 11);
	fgets(tmp2, sizeof(char) * 11 * count, stdin);
	tmp3 = strtok(tmp2, " \n");
	while (tmp3 != NULL) {
		num[i++] = atoi(tmp3);
		tmp3 = strtok(NULL, " \n");
	}
	free(tmp2);
	free(tmp3);

	while (judge(num, count) == 1) {
		splite(num, count);
		cycle++;
	}
	printf("%d\n", cycle);

	return 0;
}


/***********************************************************************************
	Function : judge
	Argument : (I/O)型;
			   int *num(整数の配列)
			   int count(整数の個数)
	Return   : (I)型
			   int* flag(配列の数がすべて2で割れるかのフラグ)
	Summary  : 配列の数がすべて2で割れるかを判定する。
               2で割れる場合1を返し、それ以外の場合0を返す。
	Caution  :
***********************************************************************************/
int judge(int *num, int count)
{
	int i, flag = 1;
	for (i = 0; i < count; i++) {
		if (num[i] % 2 != 0){
			flag = 0;
			break;
		}
	}
	return flag;
}


/***********************************************************************************
	Function : splite
	Argument : (I)型;
			   int *num(整数の配列)
			   int count(整数の個数)
	Return   : (void)型
	Summary  : 配列の数すべてを2で割った数で上書きする。
	Caution  :
***********************************************************************************/
void splite(int *num, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		num[i] /= 2;
	}
}
