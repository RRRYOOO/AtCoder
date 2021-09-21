/***********************************************************************************
	Program : main.c
	Date    : 2021.09.21    
***********************************************************************************/

#include <stdio.h>

#define COIN_A 500
#define COIN_B 100
#define COIN_C 50

void main()
{
	int coinsFiveHundred;	/* 500�~�ʂ̐�; [0-50]; */
	int coinsOneHundred;	/* 100�~�ʂ̐�; [0-50]; */
	int coinsFifty;     	/* 50�~�ʂ̐�; [0-50]; */
	int targetAmount;       /* ���v���z; [50-20000]; */
	int totalAmount = 0;    /* �R�C���̍��v���z�i�v�Z�p�j */
	int countFiveHundred;   /* 500�~�ʂ̌��i���[�v�p�j */
	int countOneHundred;    /* 100�~�ʂ̌��i���[�v�p�j */
	int countFifty;         /* 50�~�ʂ̌��i���[�v�p�j */
	int coinsPattern = 0;   /* ���傤�Ǎ��v���z�ɂȂ�R�C���̑g�ݍ��킹 */

	scanf("%d", &coinsFiveHundred);
	scanf("%d", &coinsOneHundred);
	scanf("%d", &coinsFifty);
	scanf("%d", &targetAmount);

	for (countFiveHundred = 0; countFiveHundred <= coinsFiveHundred; countFiveHundred++) {
		for (countOneHundred = 0; countOneHundred <= coinsOneHundred; countOneHundred++) {
			for (countFifty = 0; countFifty <= coinsFifty; countFifty++) {
				totalAmount = (countFiveHundred * COIN_A) + (countOneHundred * COIN_B) + (countFifty * COIN_C);
				if (totalAmount == targetAmount) {
					coinsPattern++;
				}
			}
		}
	}

	printf("%d\n", coinsPattern);
}
