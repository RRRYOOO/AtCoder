/***********************************************************************************
    Project  : project01
    FileName : main.c
    Date     : 2021.09.25
    Question : ABC_085_C
    Summary  : 青橋くんが言うには、彼が祖父から受け取ったお年玉袋には
               お札がN(1-2000)枚入っていて、合計でY(1000-20000000)円だったそうですが、
               嘘かもしれません。
               このような状況がありうるか判定し、ありうる場合はお年玉袋の中身の候補を
               一つ見つけてください。
               なお、彼の祖父は十分裕福であり、お年玉袋は十分大きかったものとします。
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THOUSAND 1000
#define TEN_BILL 10
#define FIVE_BILL 5
#define ONE_BILL 1

void main() {
    int billCount;       /* お札の合計枚数; [1-2000]; */
    int billAmount;      /* お札の合計金額（※1000分の1）; [1-20000]; */
    int tenThouCount;    /* 1万円札の枚数; */
    int fiveThouCount;   /* 5千円札の枚数; */
    int oneThouCount;    /* 千円札の枚数; */
    int sumAmount;       /* 仮定した組み合わせでの合計金額; */
    int foundFlag = 0;   /* 適合する組み合わせ発見フラグ */
    char stdinData[100]; /* 標準入力の一次保管用 */
    char *devidedNumber; /* 空白区切りの数値の一次保管用 */

    fgets(stdinData, sizeof(stdinData), stdin);
    devidedNumber = strtok(stdinData, " \n");
    billCount = atoi(devidedNumber);
    devidedNumber = strtok(NULL, " \n");
    billAmount = atoi(devidedNumber) / THOUSAND;

    for (tenThouCount = 0; tenThouCount <= billCount; tenThouCount++) {
        for (fiveThouCount = 0; (tenThouCount + fiveThouCount) <= billCount; fiveThouCount++) {
            oneThouCount = billCount - (tenThouCount + fiveThouCount);
            sumAmount = (TEN_BILL * tenThouCount) + (FIVE_BILL * fiveThouCount) + (ONE_BILL * oneThouCount);
            if (sumAmount == billAmount) {
                foundFlag = 1;
                printf("%d %d %d", tenThouCount, fiveThouCount, oneThouCount);
                break;
            }
            if (foundFlag == 1) {
                break;
            }
        }
        if (foundFlag == 1) {
            break;
        }
    }

    if (foundFlag == 0) {
        printf("-1 -1 -1\n");
    }    
}