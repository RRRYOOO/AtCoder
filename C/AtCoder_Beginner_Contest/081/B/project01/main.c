/***********************************************************************************
	Project  : project01
	FileName : main.c
	Date     : 2021.09.20
	Question : ABC_081_B
	Summary  : ���� N �̐��̐��� A1,...,AN ��������Ă��܂��D
               ���ʂ��N�́C���ɏ�����Ă��鐮�������ׂċ����ł���Ƃ��C���̑���
               ���s�����Ƃ��ł��܂��D
               ���ɏ�����Ă��鐮�����ׂĂ��C2 �Ŋ��������̂ɒu��������D
               ���ʂ��N�͍ő�ŉ��񑀍���s�����Ƃ��ł��邩�����߂Ă��������D
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
	Argument : (I/O)�^;
			   int *num(�����̔z��)
			   int count(�����̌�)
	Return   : (I)�^
			   int* flag(�z��̐������ׂ�2�Ŋ���邩�̃t���O)
	Summary  : �z��̐������ׂ�2�Ŋ���邩�𔻒肷��B
               2�Ŋ����ꍇ1��Ԃ��A����ȊO�̏ꍇ0��Ԃ��B
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
	Argument : (I)�^;
			   int *num(�����̔z��)
			   int count(�����̌�)
	Return   : (void)�^
	Summary  : �z��̐����ׂĂ�2�Ŋ��������ŏ㏑������B
	Caution  :
***********************************************************************************/
void splite(int *num, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		num[i] /= 2;
	}
}
