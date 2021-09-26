/***********************************************************************************
    Project  : project01
    FileName : main.c
    Date     : 2021.09.25
    Question : ABC_085_C
    Summary  : �����񂪌����ɂ́A�ނ��c������󂯎�������N�ʑ܂ɂ�
               ���D��N(1-2000)�������Ă��āA���v��Y(1000-20000000)�~�����������ł����A
               �R��������܂���B
               ���̂悤�ȏ󋵂����肤�邩���肵�A���肤��ꍇ�͂��N�ʑ܂̒��g�̌���
               ������Ă��������B
               �Ȃ��A�ނ̑c���͏\���T���ł���A���N�ʑ܂͏\���傫���������̂Ƃ��܂��B
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THOUSAND 1000
#define TEN_BILL 10
#define FIVE_BILL 5
#define ONE_BILL 1

void main() {
    int billCount;       /* ���D�̍��v����; [1-2000]; */
    int billAmount;      /* ���D�̍��v���z�i��1000����1�j; [1-20000]; */
    int tenThouCount;    /* 1���~�D�̖���; */
    int fiveThouCount;   /* 5��~�D�̖���; */
    int oneThouCount;    /* ��~�D�̖���; */
    int sumAmount;       /* ���肵���g�ݍ��킹�ł̍��v���z; */
    int foundFlag = 0;   /* �K������g�ݍ��킹�����t���O */
    char stdinData[100]; /* �W�����͂̈ꎟ�ۊǗp */
    char *devidedNumber; /* �󔒋�؂�̐��l�̈ꎟ�ۊǗp */

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