#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 8 // define max size
long long int bishop(int n, int k);
void main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) && (n || k))
	{
		long long int result = bishop(n, k);
		printf("The result takes %d\n", result);
	}
}
long long int bishop(int n, int k)
{
	// set the exception 
	if (n == 1) 
	{
		return 1;
	}
	if (k > 2 * n - 2) 
	{
		return 0;
	}
	// set the exception 
	long long result = 0;
	// black board
	long long int black[9][15];
	// white board
	long long int white[9][15];
	long long int row_b[9];
	long long int row_w[9];
    // memory allocation 
	memset(black, 0, sizeof(black));
	memset(white, 0, sizeof(white));
	memset(row_b, 0, sizeof(row_b));
	memset(row_w, 0, sizeof(row_w));
	// set black board and white board row. 
	for (int i = 1; i <= MAX; i++) 
	{
		if ((i % 2) == 1)
		{
			row_b[i] = i;
		}
		else
		{
			row_b[i] = row_b[i - 1];
		}
	}
	for (int i = 1; i <= MAX; i++)
	{
		if ((i % 2) == 1)
		{
			row_w[i] = i + 1;
		}
		else
		{
			row_w[i] = row_w[i - 1];
		}
	}
	for (int i = 0; i <= n; i++)
	{
		black[i][0] = 1;
	}
	for (int i = 0; i <= n; i++)
	{
		white[i][0] = 1;
	}
	// computing phase
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k && j <= i; j++)
		{
			black[i][j] = black[i - 1][j] + black[i - 1][j - 1] * (row_b[i] - (j - 1)); // counts the computation and insert it. (black)

		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k && j <= i; j++)
		{
			white[i][j] = white[i - 1][j] + white[i - 1][j - 1] * (row_w[i] - (j - 1)); // count the computation and insert it. (white
		}
	}

	for (int i = 0; i <= k; i++)
	{
		result += black[n][i] * white[n - 1][k - i]; // get the result of coputation 
	}
	return result;
}