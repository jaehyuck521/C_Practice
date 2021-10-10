#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// File author:¿Â¿Á«ı date: 2021-09-16
// This is a program, first when we get two inputs from user.(num1, num2) and 
// insert the two inputs and 4 store variables, Then function calculates with two input, 4 operation.
// then function calculates all operation and save the data to 4 variables. And print the result. 
void calculate(int* n1, int* n2, int* rel1, int* rel2, int* rel3, int* rel4); // declare the function
void main()
{
	int n1, n2 = 0; // two variables and get the two input n1, n2
	printf("Press the first number\n");
	scanf("%d", &n1);
	printf("Press the Second number\n");
	scanf("%d", &n2);
	// we have divide result, So if n2==0 it is not acceptable. So we make the exception. 
	if (n2 == 0) 
	{
		printf("You can insert the second number 0\n");
		printf("Re press the second number except 0\n");
		scanf("%d", &n2);
	}
	int multiply, divide, moduler, add=0; // the variables for saving result of calculate
	// execute function. 
	calculate(&n1, &n2, &multiply, &divide, &moduler, &add);
	// print the result.
	printf("The multiply result of n1 & n2:  %d \n", multiply);
	printf("The divde result of n1 & n2:  %d \n", divide);
	printf("The moduler result of n1 & n2:  %d \n", moduler);
	printf("The add result of n1 & n2:  %d \n", add);
}
// the function calcualte the n1 & n2
// caculate the operation: multiply, divide, moduler, add 
// save the result of operation to variables. 
void calculate(int *n1, int *n2, int *re1, int *re2, int *re3, int *re4)
{
	int num1 = *n1;
	int num2 = *n2;
	*re1 = num1 + num2;
	if(num2!=0) // check the num2 is 0 
	{
		*re2 = num1 / num2;
	}
	*re3 = num1 % num2;
	*re4 = num1 + num2;
}