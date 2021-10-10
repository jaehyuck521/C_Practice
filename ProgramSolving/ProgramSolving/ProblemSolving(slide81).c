#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
//File :author: ÀåÀçÇõ date: 2021-09-16
// the program that gets the input from user(base & overtime) and execute extern function totpay. and print the 
// result of the calculation So, the output is base+overtime-> total pay. 
void totpay(float[5], float[5], float[5]); //declare the function totpay
//main function
void main()
{
	int i = 0;
	float base[5], overtime[5], total[5]; //variables
	while(i<5)
	{
		printf("Enter the base salaries!  \n");
		scanf("%f", &base[i]);
		printf("Enter the overtime salaries! \n");
		scanf("%f", &overtime[i]);
		if (base[i] < 0 || overtime[i] < 0)
		{
			printf("Invalid value, You should re-type it. ");
			i--;
		}
		i++;
	}
	// get the input from user five base and overtime
	totpay(base, overtime, total); //execute function
	// print the result.
	for (int i = 0; i < 5; i++)
	{
		printf("Total %d 's salary: %f \n", i, total[i]);
	}
}
 // The function caculate the total pay: 
// The operation is basetime+ overtime and save the result to total array. 
void totpay(float b[], float o[], float t[])
{
	for (int i = 0; i < 5; i++)
	{
		t[i] = b[i] + o[i];
	}
}