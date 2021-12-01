
// autho: 21533667 ¿Â¿Á«ı date: 2021-12-01
// this program is stack program by array. we have 4 functions push, pop, stack_full, stack_empty 
// by using this function we can insert and delete the value 
// define the function
#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void push(int);
int pop();
int stack_full();
int stack_empty();
// and set the global variable
int top = -1;
int arr[10];
void main()
{
	int sel = 0; // for the selection 
	int data = 0; //for the inserting data
	int run = 1; 
	while (run)
	{
		printf("1.push 2.pop 3.end\n");
		scanf("%d", &sel);
		if (sel == 1)
		{
			if (stack_full() == 1) // defensive coding
			{
				printf("full stack");
				printf("\n");
			}
			else
			{
				scanf("%d", &data);
				push(data);
			}
		}
		if (sel == 2)
		{
			if (stack_empty() == 1) // defensive coding
			{
				printf("empty stack");
				printf("\n");
			}
			else
			{
				data = pop();
				printf("popped data is %d", data);
				printf("\n");
			}
		}
		if (sel == 3) // end
		{
			run = -1;
		}
	}
}
// this function push the data in stack and increment top.
void push(int data)
{
	top = top + 1;
	arr[top] = data;
}
// this function pop the data from the stack and decrement top and after deleted fill the deleted area to null
int pop()
{
	int temp = arr[top];
	arr[top] = NULL;
	top = top - 1;
	return temp;
}
// this function checks the stack is full by measuring the top when top is 9 it is full
int stack_full()
{
	if (top == 9)
	{
		return 1;
	}
	else
		return 0;
}
// this function checks the the stack is empty. if empty return 0, else return 1
int stack_empty()
{
	if (top == -1)
	{
		return 1;
	}
	else return 0;
}




