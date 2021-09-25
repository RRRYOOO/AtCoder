/***********************************************************************************
    Project  : project01
	FileName : main.c
	Date     : 2021.09.23
	Question : ABC_083_B
	Summary  : 1以上N以下の整数のうち、10進法で各桁の和がA以上B以下であるもの
	           について、総和を求めてください。
***********************************************************************************/
#include <stdio.h>

void main()
{
	int inputNumber;           /* 入力された数値; [1-10000]; */
	int underLimit;            /* カウント対象となる各桁和の下限; [1-upperLimit];	*/
	int upperLimit;            /* カウント対象となる各桁和の下限; [underLimit-36];	*/
	int validNumberSum = 0;    /* 条件を満たす数値の合計; */
	int devidedNumber;         /* 入力された数値を"%10"した数値を格納（計算用） */
	int sumEachDigit;          /* 各桁の合計値（計算用） */
	int i;                     /* ループ用変数 */

	scanf("%d %d %d", &inputNumber, &underLimit, &upperLimit);
	for (i = underLimit; i <= inputNumber; i++) {
		devidedNumber = i;
		sumEachDigit = 0;
		while (devidedNumber >= 10) {
			sumEachDigit += devidedNumber % 10;
			devidedNumber /= 10;
		}
		sumEachDigit += devidedNumber;

		if ((underLimit <= sumEachDigit) && (sumEachDigit <= upperLimit)) {
			validNumberSum += i;
		}
	}
	
	printf("%d\n", validNumberSum);
}