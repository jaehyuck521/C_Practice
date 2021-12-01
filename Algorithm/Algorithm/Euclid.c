#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int euclid(int a, int b, int* x, int* y);

void main()
{
	int num1, num2, result, rx = 0, ry = 0;
	FILE* fp = fopen("input.txt", "rt");

	if (fp == NULL)
	{
		puts("error\n");
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %d", &num1, &num2);
		if (num1 > 1000000000 || num2 > 1000000000)
		{
			printf("error\n");
			break;
		}
		result = euclid(num1, num2, &rx, &ry);
		printf("%d %d %d\n", rx, ry, result);
		num1 = 0;
		num2 = 0;
		result = 0;
	}
	fclose(fp);
}

int euclid(int a, int b, int* x, int* y)
{
	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}

	int g = euclid(b, a % b, x, y);

	int temp1 = *y, temp2 = *x;
	*x = temp1;
	*y = (temp2 - (int)(a / b) * temp1);
	return g;
}

