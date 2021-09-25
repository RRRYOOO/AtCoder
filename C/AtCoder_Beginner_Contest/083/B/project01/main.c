/***********************************************************************************
    Project  : project01
	FileName : main.c
	Date     : 2021.09.23
	Question : ABC_083_B
	Summary  : 1�ȏ�N�ȉ��̐����̂����A10�i�@�Ŋe���̘a��A�ȏ�B�ȉ��ł������
	           �ɂ��āA���a�����߂Ă��������B
***********************************************************************************/
#include <stdio.h>

void main()
{
	int inputNumber;           /* ���͂��ꂽ���l; [1-10000]; */
	int underLimit;            /* �J�E���g�ΏۂƂȂ�e���a�̉���; [1-upperLimit];	*/
	int upperLimit;            /* �J�E���g�ΏۂƂȂ�e���a�̉���; [underLimit-36];	*/
	int validNumberSum = 0;    /* �����𖞂������l�̍��v; */
	int devidedNumber;         /* ���͂��ꂽ���l��"%10"�������l���i�[�i�v�Z�p�j */
	int sumEachDigit;          /* �e���̍��v�l�i�v�Z�p�j */
	int i;                     /* ���[�v�p�ϐ� */

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