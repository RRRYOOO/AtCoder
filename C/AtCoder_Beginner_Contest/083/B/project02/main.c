/***********************************************************************************
	Program : main.c
	Date    : 2021.09.23
***********************************************************************************/

#include <stdio.h>

int SumDigit(int objectNum);

void main()
{
	int inputNumber;           /* ���͂��ꂽ���l; [1-10000]; */
	int underLimit;            /* �J�E���g�ΏۂƂȂ�e���a�̉���; [1-upperLimit];	*/
	int upperLimit;            /* �J�E���g�ΏۂƂȂ�e���a�̉���; [underLimit-36];	*/
	int sumResult;             /* ���l�̊e�������킹���� */
	int validNumberSum = 0;    /* �����𖞂������l�̍��v; */
	int i;                     /* ���[�v�p�ϐ� */

	scanf("%d %d %d", &inputNumber, &underLimit, &upperLimit);
	for (i = underLimit; i <= inputNumber; i++) {
		sumResult = SumDigit(i);
		if ((underLimit <= sumResult) && (sumResult <= upperLimit)) {
			validNumberSum += i;
		}
	}
	printf("%d\n", validNumberSum);
}

int SumDigit(int objectNum)
{
	int sumEachDigit = 0;          /* �e���̍��v�l�i�v�Z�p�j */
	
	while (objectNum >= 10) {
		sumEachDigit += objectNum % 10;
		objectNum /= 10;
	}
	sumEachDigit += objectNum;
	
	return sumEachDigit;
}