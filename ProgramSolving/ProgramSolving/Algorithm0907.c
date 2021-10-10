#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void main()
{
	int num;
	int total[100];
	int temp;
	int personalCost;
	int exchange = 0;
	
	int i = 0;
	while(1)
	{
		 scanf("%d", &num);
		 for (int i = 0; i < num; i++)
		 {
			 personalCost = scanf("%d", &temp);
			 if (personalCost < 100000 && personalCost>0)
			 {
				 total[i] = personalCost;
			 }
			 else if (personalCost == 0)
			 {
				 break;
			 }
			 else
			 {
				 printf("Press the valid value");
			 }

		 }		 
		 int totalCost = 0;
		 for (int i = 0; i < sizeof(total) / sizeof(int); i++)
		 {
			 totalCost = totalCost + total[i];
		 }
		 for (int i = 0; i < sizeof(total) / sizeof(int); i++)
		 {
			 int avr = totalCost / num;
			 
		 }

	}






}