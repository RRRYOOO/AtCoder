/***********************************************************************************
    Project  : project02
    FileName : main.c
    Date     : 2021.09.23
    Question : ABC_083_B
    Summary  : 1�ȏ�N�ȉ��̐����̂����A10�i�@�Ŋe���̘a��A�ȏ�B�ȉ��ł������
               �ɂ��āA���a�����߂Ă��������B
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


/***********************************************************************************
    Function : SumDigit
    Argument : (I/O)�^;
               int objectNum(�v�Z�Ώۂ̐��l)
    Return   : (I)�^
               int sumEachDigit(�e���̍��v�l)
    Summary  : �n���ꂽ���l�̊e���̍��v�l��Ԃ�
    Caution  :
***********************************************************************************/
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