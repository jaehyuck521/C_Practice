#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
struct stock {
	float eps;
	char name[20];
	float ptec;
};
void main()
{
	struct stock st[5];
	for (int i = 0; i < 5; i++)
	{
		printf("Press the Stock Name: ");
		scanf("%s", st[i].name);
		printf("Press the earnings per share:  ");
		scanf("%f", &st[i].eps);
		if (st[i].eps < 0)
		{
			printf("\n Retype Please");
			scanf("%f", &st[i].eps);
		}
		printf("Press the price to earnings:  ");
		scanf("%f", &st[i].ptec);
		if (st[i].ptec < 0)
		{
			printf("\n Retype Please");
			scanf("%f", &st[i].ptec);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("The anticipated price for a share of %s stock is (%f)*(%f)=%f \n", st[i].name, st[i].eps, st[i].ptec, st[i].eps * st[i].ptec);
	}
}