//	2021.09.20

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

//	‚·‚×‚Ä2‚ÅŠ„‚ê‚éê‡‚ÍA1‚ğ•Ô‚·
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

//	“n‚³‚ê‚½”z—ñ‚Ì—v‘f‚ğ‚·‚×‚Ä'Š„‚é2'‚·‚é
void splite(int *num, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		num[i] /= 2;
	}
}
