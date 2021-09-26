/***********************************************************************************
    Project  : project01
    FileName : main.c
    Date     : 2021.09.26
    Question : ABC_085_B
    Summary  : ����������N���̉~�`�̖݂������Ă��āA���̂���i���ڂ̖݂̒��a��
               di�Z���`���[�g���ł��B�����̖݂̂����ꕔ�܂��͑S�����g���ċ���
               �����Ƃ��A�ő�ŉ��i�d�˂̋��݂���邱�Ƃ��ł���ł��傤���B
               (�ǂ̖݂����̐^���̖݂�蒼�a���������i��ԉ��̖݂������j�K�v������)
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int CompareNumber(const void *leftNumber, const void *rightNumber);
int CountRadius(int *mochiRadius, int mochiCount);

void main()
{
    int mochiCount;        /* �݂̐�(N); [1-100]; */
    int *mochiRadius;      /* �݂̒��a�̎��; [1 - 100]; */
    int radiusCount = 0;   /* ���a�̎�ސ�; */
    int i;                 /* ���[�v�p; */
    char stdinData[1000];  /* �W�����͂̈ꎟ�ۊǗp; */

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
    Argument : (I/O)�^;
               void *leftNumber(��r�Ώۂ̐��l���C���f�b�N�X��ԁj
               void *rightNumber(��r�Ώۂ̐��l���C���f�b�N�X�V�ԁj
    Return   : int(��r����)
    Summary  : �n���ꂽ�|�C���^�ɔz�u���ꂽ���l�ŁA�C���f�b�N�X�V�Ԃ��傫��������1
               �C���f�b�N�X��Ԃ��傫��������1�A����ȊO�̏ꍇ0��Ԃ��B
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
    Argument : (I/O)�^;
               int *mochiRadius(�J�E���g�Ώۂ̔z��̐擪�A�h���X�j
               int mochiCount(�݂̌�)
    Return   : int radiusCount(���a�̎�ސ�)
    Summary  : �n���ꂽ�z��Ɋi�[����Ă���݂̒��a�̎�ނ��������邩�J�E���g����
    Caution  :
***********************************************************************************/
int CountRadius(int* mochiRadius, int mochiCount)
{
    int radiusCount = 1;    /* ���a�̎�ސ�; */
    int i;                  /* ���[�v�p */

    for (i = 1; i < mochiCount; i++) {
        if (mochiRadius[i] < mochiRadius[i - 1]) {
            radiusCount++;
        }
    }
    return radiusCount;
}