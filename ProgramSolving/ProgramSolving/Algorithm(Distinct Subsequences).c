
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void main()
{
	char s[100]; //ex. rabbbit
	char t[100]; // ex. rabbit

	printf("enter the sequence: ");
	scanf("%s", &s);

	printf("enter the subsequence: ");
	scanf("%s", &t);

	int x = 0, y = 0, i = 0, j = 0;

	x = strlen(s); // length of s
	y = strlen(t); // length of t


	int table[100][100]; // I made the table for sloving 

	for (i = 0; i < x; i++) // Initialize the table to 0
	{
		for (j = 0; j < y; j++)
			table[i][j] = 0;
	}

	char c = s[0];
	for (i = 0; i < x; i++) // All table[][0] to 1
	{
		if (i == 0)
			table[i][0] = 0;
		else
			table[i][0] = table[i - 1][0];

		if (s[i] == c)
			table[i][0] = table[i][0] + 1;
		else
			table[i][0] = table[i][0] + 0;
	}
	for (i = 0; i  < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	printf("---------------\n");
	for (i = 1; i < x; i++) // Calculate the table
	{
		c = s[i];
		for (j = 1; j < y; j++)
		{
			table[i][j] = table[i - 1][j]; // copy the left element.
			if (t[j] == c) // add the integer at left diagonal.
				table[i][j] = table[i][j] + table[i - 1][j - 1];
		}
	}
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}

	printf("%d", table[x - 1][y - 1]);
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** createTable(int _num_r, int _num_c)
{
	int** res_table = (int**)malloc(_num_r * (sizeof(int*)));
	for (int i = 0; i < _num_r; i++) 
	{
		res_table[i] = (int*)malloc(_num_c * (sizeof(int)));
	}
	return res_table;
}

int getMinimum(int a, int b, int c) 
{
	if (a <= b && a <= c) return a;
	else if (b <= a && b <= c) return b;
	else if (c <= a && c <= b) return c;
}

void populateTable(int** _table, char* _s1, char* _s2, int _num_row, int _num_col) 
{

	// 1행 채우기
	for (int i = 0; i < _num_col; i++) 
	{
		_table[0][i] = i;
	}
	// 1열 채우기
	for (int i = 0; i < _num_row; i++)
	{
		_table[i][0] = i;
	}

	// 나머지 칸들 채우기
	for (int i = 1; i < _num_row; i++) 
	{
		for (int j = 1; j < _num_col; j++) 
		{
			if (_s1[i - 1] == _s2[j - 1]) 
			{ // 마지막 글자가 같다면,
				_table[i][j] = _table[i - 1][j - 1];
			}
			else 
			{
				_table[i][j] = getMinimum(_table[i][j - 1], _table[i - 1][j], _table[i - 1][j - 1]) + 1; // 좌, 상, 대각선
			}
		}
	}
}

int main(void)
{

	// s1(행) -> s2(열)
	char* s1 = "strong";
	char* s2 = "storm";

	int num_row = strlen(s1) + 1; // 처음의 " "(공백)을 포함하여 +1을 해준다.  // 7
	int num_col = strlen(s2) + 1;                                              // 6

	int** table = createTable(num_row, num_col); // 동적 배열을 생성해서 return 해준다.

	populateTable(table, s1, s2, num_row, num_col); // table을 채우는 함수.

	printf("\n----------------------Edit Distance----------------------\n");
	printf("num row : %d  \nnum_col : %d\n", num_row, num_col);
	for (int i = 0; i < num_row; i++) 
	{
		for (int j = 0; j < num_col; j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}
