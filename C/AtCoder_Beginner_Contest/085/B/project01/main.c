/***********************************************************************************
    Project  : project01
    FileName : main.c
    Date     : 2021.09.26
    Question : ABC_085_B
    Summary  : ルンルンはN枚の円形の餅を持っていて、そのうちi枚目の餅の直径は
               diセンチメートルです。これらの餅のうち一部または全部を使って鏡餅
               を作るとき、最大で何段重ねの鏡餅を作ることができるでしょうか。
               (どの餅もその真下の餅より直径が小さい（一番下の餅を除く）必要がある)
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int CompareNumber(const void *leftNumber, const void *rightNumber);
int CountRadius(int *mochiRadius, int mochiCount);

void main()
{
    int mochiCount;        /* 餅の数(N); [1-100]; */
    int *mochiRadius;      /* 餅の直径の種類; [1 - 100]; */
    int radiusCount = 0;   /* 直径の種類数; */
    int i;                 /* ループ用; */
    char stdinData[1000];  /* 標準入力の一次保管用; */

    fgets(stdinData, sizeof(stdinData), stdin);
    sscanf(stdinData, "%d", &mochiCount);
    mochiRadius = (int*)malloc(mochiCount * sizeof(mochiCount));

;   for (i = 0; i < mochiCount; i++) {
        fgets(stdinData, sizeof(stdinData), stdin);
        sscanf(stdinData, "%d", &mochiRadius[i]);
    }
    
    qsort(mochiRadius, mochiCount, sizeof(int), CompareNumber);
    radiusCount = CountRadius(mochiRadius, mochiCount);
    printf("%d\n", radiusCount);

    free(mochiRadius);
    mochiRadius = NULL;
}


/***********************************************************************************
    Function : CompareNumber
    Argument : (I/O)型;
               void *leftNumber(比較対象の数値※インデックス若番）
               void *rightNumber(比較対象の数値※インデックス老番）
    Return   : int(比較結果)
    Summary  : 渡されたポインタに配置された数値で、インデックス老番が大きかったら1
               インデックス若番が大きかったら1、それ以外の場合0を返す。
    Caution  :
***********************************************************************************/
int CompareNumber(const void *leftNumber, const void *rightNumber)
{
    if (*(int *)leftNumber < *(int *)rightNumber) {
        return 1;
    }
    else if (*(int *)rightNumber < *(int *)leftNumber) {
        return -1;
    }
    else {
        return 0;
    }
}


/***********************************************************************************
    Function : CountRadius
    Argument : (I/O)型;
               int *mochiRadius(カウント対象の配列の先頭アドレス）
               int mochiCount(餅の個数)
    Return   : int radiusCount(直径の種類数)
    Summary  : 渡された配列に格納されている餅の直径の種類がいくつあるかカウントする
    Caution  :
***********************************************************************************/
int CountRadius(int* mochiRadius, int mochiCount)
{
    int radiusCount = 1;    /* 直径の種類数; */
    int i;                  /* ループ用 */

    for (i = 1; i < mochiCount; i++) {
        if (mochiRadius[i] < mochiRadius[i - 1]) {
            radiusCount++;
        }
    }
    return radiusCount;
}