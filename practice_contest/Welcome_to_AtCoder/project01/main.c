//	2021.09.20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABC 3

int main() {
	int i = 0, j, sum = 0;
	char str[32], *temp1, *temp2;
	
	temp1 = (char*)malloc(sizeof(char) * 100);
	temp2 = (char*)malloc(sizeof(char) * 4);
	while (i < ABC)
	{
		fgets(temp1, sizeof(temp1), stdin);
		temp2 = strtok(temp1, " \n");
		while (temp2 != NULL) {
			sum += atoi(temp2);
			i++;
			temp2 = strtok(NULL, ", \n");
		}
	}
	scanf("%s", str);
	printf("%d %s\n", sum, str);
	free(temp1);
	free(temp2);

	return 0;
}
