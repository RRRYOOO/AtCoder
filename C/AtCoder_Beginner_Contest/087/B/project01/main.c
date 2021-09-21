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
	int coinsFiveHundred;	/* 500円玉の数; [0-50]; */
	int coinsOneHundred;	/* 100円玉の数; [0-50]; */
	int coinsFifty;     	/* 50円玉の数; [0-50]; */
	int targetAmount;       /* 合計金額; [50-20000]; */
	int totalAmount = 0;    /* コインの合計金額（計算用） */
	int countFiveHundred;   /* 500円玉の個数（ループ用） */
	int countOneHundred;    /* 100円玉の個数（ループ用） */
	int countFifty;         /* 50円玉の個数（ループ用） */
	int coinsPattern = 0;   /* ちょうど合計金額になるコインの組み合わせ */

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
