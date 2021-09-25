/***********************************************************************************
    Project  : project02
    FileName : main.c
    Date     : 2021.09.25
    Question : ABC_088_B
    Summary  : N 枚のカードがあり、i 枚目のカードには, ai​という数が書かれています.
               Alice と Bob は, これらのカードを使ってゲームを行います.
			   ゲームでは, Alice と Bob が交互に 1 枚ずつカードを取っていきます.
			   Alice が先にカードを取ります.
			   2 人がすべてのカードを取ったときゲームは終了し, 取ったカードの数の
			   合計がその人の得点になります.
			   2 人とも自分の得点を最大化するように最適な戦略を取った時,
			   Alice は Bob より何点多く取るか求めてください.
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CompareNumber(const void *leftNumber, const void *rightNumber);

void main()
{
	int cardCount;             /* カードの枚数 */
	int *cardsArray;           /* カードの数値を格納する配列; [1-100] */
	int sumAlicePoint = 0;     /* Aliceの合計ポイント */
	int sumBobPoint = 0;       /* Bobの合計ポイント */
	int defferencePoint = 0;   /* 二人のポイントの差 */
	int i;                     /* ループ用 */
	char stdinData[1000];      /* 標準入力の一次保管用; */
	char *devidedNum;          /* 空白区切りで分割したの数字の一次保管用; */

	fgets(stdinData, sizeof(stdinData), stdin);
	sscanf(stdinData, "%d", &cardCount);
	
	fgets(stdinData, sizeof(stdinData), stdin);
	devidedNum = strtok(stdinData, " \n");
	cardsArray = (int*)malloc(cardCount * sizeof(int));
	cardsArray[0] = atoi(devidedNum);
	for (i = 1; i < cardCount; i++) {
		devidedNum = strtok(NULL, " \n");
		cardsArray[i] = atoi(devidedNum);
	}
	qsort(cardsArray, cardCount, sizeof(int), CompareNumber);

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
    Function : CompareNumber
    Argument : (I/O)型;
			   void *leftNumber(比較対象の数値※インデックス若番）
			   void *rightNumber(比較対象の数値※インデックス老番）
    Return   : (I)型
    Summary  : 渡されたポインタに配置された数値で、インデックス老番が大きかったら1
			   インデックス若番が大きかったら1、それ以外の場合0を返す。
    Caution  :
***********************************************************************************/
int CompareNumber(const void *leftNumber, const void *rightNumber)
{
	if (*(int*)leftNumber < *(int*)rightNumber) {
		return 1;
	}
	else if (*(int*)rightNumber < *(int*)leftNumber) {
		return -1;
	}
	else {
		return 0;
	}
}