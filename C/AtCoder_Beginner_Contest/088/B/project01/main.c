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
	int cardCount;             /* �J�[�h�̖���; [1-100]*/
	int *cardsArray;           /* �J�[�h�̐��l���i�[����z��ւ̃|�C���^; */
	int sumAlicePoint = 0;     /* Alice�̍��v�|�C���g */
	int sumBobPoint = 0;       /* Bob�̍��v�|�C���g */
	int defferencePoint = 0;   /* ��l�̃|�C���g�̍� */
	int i;                     /* ���[�v�ϐ��i�v�Z�p�j; */
	char temp[1000];           /* �ꎟ�ۊǗp; */
	char *str;                 /* �ꎟ�ۊǗp; */

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
	�E�n���ꂽ�z���傫�����ɕ��ёւ���
***********************************************************************************/
void ChangeArrayOeder(int *cardsArray, int cardCount)
{
	int *orderingArray;        /* ����p�̔z��; */
	int *maxNumberAddress;     /* ����p�z��̍ő�l�̃A�h���X; */
	int i;                     /* ���[�v�ϐ��i�v�Z�p�j; */

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
	�E�n���ꂽ�z��̒��ōő�l�����v�f�̃A�h���X��Ԃ�
***********************************************************************************/
int* PickUpMaxNumberAddress(int *cardsArray, int cardCount)
{
	int *maxNumberAddress;     /* �z��̒��̍ő�̐��l���i�[����Ă���A�h���X; */
	int i;                     /* ���[�v�ϐ��i�v�Z�p�j; */
	
	maxNumberAddress = cardsArray;
	for (i = 0; i < cardCount; i++) {
		if (*maxNumberAddress < cardsArray[i]) {
			maxNumberAddress = cardsArray + i;
		}
	}
	return maxNumberAddress;
}