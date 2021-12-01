#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 200
void coloring(int node, int c);

static int edge, graph[MAXNUM][MAXNUM];
static int color[MAXNUM];
static int colorable;

void main()
{
	FILE* fp;
	fp = fopen("input.txt", "r");
	int node = 0, x = 0, y = 0;

	if (fp == NULL)
	{
		puts("error");
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &edge);
		for (int i = 0; i < edge; i++)
		{
			for (int j = 0; j < edge; j++)
				graph[i][j] = 0;
		}

		fscanf(fp, "%d", &node);

		for (int i = 0; i < node; i++)
		{
			fscanf(fp, "%d %d", &x, &y);
			graph[x][y] = 1;
			graph[y][x] = 1;

		}
		for (int i = 0; i < edge; i++)
			color[i] = 0;

		colorable = 1;
		coloring(0, 1);

		if (colorable == 0)
			printf("not two-color\n");
		else
			printf("two-color\n");
	}

	for (int i = 0; i < edge; i++)
	{
		for (int j = 0; j < edge; j++)
			graph[i][j] = 0;
	}
	for (int i = 0; i < edge; i++)
		color[i] = 0;

	fclose(fp);
}

void coloring(int node, int c)
{
	color[node] = c;
	for (int i = 0; i < edge && colorable; i++)
	{
		if (graph[node][i] == 0)
			continue;

		if (color[i] == 0)
			coloring(i, c % 2 + 1);

		else
		{
			if (color[i] == c)
			{
				colorable = 0;
			}
		}
	}
}

