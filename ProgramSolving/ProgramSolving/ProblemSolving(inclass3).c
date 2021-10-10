#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void liquid(int, int *, int *, int *, int *);
void main()
{
	int num=0;
	printf("Press the number of cup \n");
	scanf("%d",&num);
	if (num < 0)
	{
		printf("invalid value!!");
		scanf("%d",&num);
	}
	int gall, quart, pint, cup=0;
	liquid(num, &gall, &quart, &pint, &cup);
	printf("Total gallon is: %d quarts is : %d pint is : %d cup is : %d", gall, quart, pint, cup);


}
void liquid(int num, int *gallon, int *quart, int *pint, int *cup)
{
	*gallon = num / 16;
	*quart = num %16 / 4;
	*pint = num % 16 % 4 / 2;
	*cup = num % 16 % 4 % 2;

}