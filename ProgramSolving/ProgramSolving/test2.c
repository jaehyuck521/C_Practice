#include<stdio.h>
#define MAX 10
void main()
{
	int arr_input[MAX] = { 1,2,3,5 };

	int arr_a[MAX] = { 0, };
	int arr_b[MAX] = { 0, };

	int arr_a_last = 0;
	int arr_b_last = 0;

	int a = 0;
	int b = 0;

	

	for (int i = 0; i < MAX; ++i)
	{
		if (a <= b)
		{
			a += arr_input[i];
			arr_a[arr_a_last] = arr_input[i]; // 확인용
			++arr_a_last; // 확인용
		}
		else if (a > b)
		{
			b += arr_input[i];
			arr_b[arr_b_last] = arr_input[i]; // 확인용
			++arr_b_last; // 확인용
		}
	}
	printf("%d", a);
	printf("%d", b);
	printf("%d", a - b);
}
