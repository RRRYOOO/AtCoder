/***********************************************************************************
	Program : main.c
	Date    : 2021.09.23
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void ChangeArrayOeder(int* cardsArray, int cardCount);
int* PickUpMaxNumberAddress(int* cardsArray, int cardCount);

void main()
{
	int cardCount;             /* カードの枚数; [1-100]*/
	int *cardsArray;           /* カードの数値を格納する配列へのポインタ; */
	int sumAlicePoint = 0;     /* Aliceの合計ポイント */
	int sumBobPoint = 0;       /* Bobの合計ポイント */
	int defferencePoint = 0;   /* 二人のポイントの差 */
	int i;                     /* ループ変数（計算用）; */
	char temp[1000];           /* 一次保管用; */
	char *str;                 /* 一次保管用; */

	fgets(temp, sizeof(temp), stdin);
	sscanf(temp, "%d", &cardCount);
	cardsArray = (int*)malloc(cardCount * sizeof(int));
	fgets(temp, sizeof(temp), stdin);
	str = strtok(temp, " ");
	for (i = 0; i < cardCount; i++) {
		cardsArray[i] = atoi(str);
		str = strtok(NULL, " ");
	}

	ChangeArrayOeder(cardsArray, cardCount);
	
	for (i = 0; i < cardCount; i++) {
		if ((i % 2) == 0) {
			sumAlicePoint += cardsArray[i];
		}
		else {
			sumBobPoint += cardsArray[i];
		}
	}
	defferencePoint = sumAlicePoint - sumBobPoint;
	printf("%d", defferencePoint);

	free(cardsArray);
	cardsArray = NULL;
}


/***********************************************************************************
	・渡された配列を大きい順に並び替える
***********************************************************************************/
void ChangeArrayOeder(int *cardsArray, int cardCount)
{
	int *orderingArray;        /* 整列用の配列; */
	int *maxNumberAddress;     /* 整列用配列の最大値のアドレス; */
	int i;                     /* ループ変数（計算用）; */

	orderingArray = (int*)malloc(cardCount * sizeof(int));
	memcpy(orderingArray, cardsArray, cardCount * sizeof(int));	
	for (i = 0; i < cardCount; i++) {
		maxNumberAddress = PickUpMaxNumberAddress(orderingArray, cardCount);
		cardsArray[i] = *maxNumberAddress;
		*maxNumberAddress = -1;
	}
	free(orderingArray);
	orderingArray = NULL;
}

/***********************************************************************************
	・渡された配列の中で最大値を持つ要素のアドレスを返す
***********************************************************************************/
int* PickUpMaxNumberAddress(int *cardsArray, int cardCount)
{
	int *maxNumberAddress;     /* 配列の中の最大の数値が格納されているアドレス; */
	int i;                     /* ループ変数（計算用）; */
	
	maxNumberAddress = cardsArray;
	for (i = 0; i < cardCount; i++) {
		if (*maxNumberAddress < cardsArray[i]) {
			maxNumberAddress = cardsArray + i;
		}
	}
	return maxNumberAddress;
}