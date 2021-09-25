/***********************************************************************************
    Project  : project02
    FileName : main.c
    Date     : 2021.09.23
    Question : ABC_083_B
    Summary  : 1以上N以下の整数のうち、10進法で各桁の和がA以上B以下であるもの
               について、総和を求めてください。
***********************************************************************************/
#include <stdio.h>

int SumDigit(int objectNum);

void main()
{
	int inputNumber;           /* 入力された数値; [1-10000]; */
	int underLimit;            /* カウント対象となる各桁和の下限; [1-upperLimit];	*/
	int upperLimit;            /* カウント対象となる各桁和の下限; [underLimit-36];	*/
	int sumResult;             /* 数値の各桁を合わせた数 */
	int validNumberSum = 0;    /* 条件を満たす数値の合計; */
	int i;                     /* ループ用変数 */

	scanf("%d %d %d", &inputNumber, &underLimit, &upperLimit);
	for (i = underLimit; i <= inputNumber; i++) {
		sumResult = SumDigit(i);
		if ((underLimit <= sumResult) && (sumResult <= upperLimit)) {
			validNumberSum += i;
		}
	}
	printf("%d\n", validNumberSum);
}


/***********************************************************************************
    Function : SumDigit
    Argument : (I/O)型;
               int objectNum(計算対象の数値)
    Return   : (I)型
               int sumEachDigit(各桁の合計値)
    Summary  : 渡された数値の各桁の合計値を返す
    Caution  :
***********************************************************************************/
int SumDigit(int objectNum)
{
	int sumEachDigit = 0;          /* 各桁の合計値（計算用） */
	
	while (objectNum >= 10) {
		sumEachDigit += objectNum % 10;
		objectNum /= 10;
	}
	sumEachDigit += objectNum;
	
	return sumEachDigit;
}