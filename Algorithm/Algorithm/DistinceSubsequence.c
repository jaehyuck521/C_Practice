#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char s[100]; 
	char t[100]; 

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
	printf("%d", table[x - 1][y - 1]);

}
