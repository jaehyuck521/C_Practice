#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define CENTER_NUM 100
#define DISTANCE_MAX 214748364 //int형 타입이 가질 수 있는 큰 수
#define ROAD_MAX 500
#define INTERSECTION_MAX 20
void init();
void floyd(int roadNum, int distance[ROAD_MAX][ROAD_MAX]);

int isCenter[CENTER_NUM];
int distance[ROAD_MAX][ROAD_MAX];

void init()
{
	for (int i = 0; i < CENTER_NUM; i++)
	{
		isCenter[i] = 0;
	}
	for (int i = 0; i < ROAD_MAX; i++)
	{
		for (int j = 0; j < ROAD_MAX; j++)
			distance[i][j] = DISTANCE_MAX;
		distance[i][i] = 0;
	}
}

// 플로이드 알고리즘
void floyd(int roadNum, int distance[ROAD_MAX][ROAD_MAX])
{
	for (int i = 0; i < roadNum; i++)
		for (int j = 0; j < roadNum; j++)
			for (int k = 0; k < roadNum; k++)
				if (distance[j][k] > distance[j][i] + distance[i][k])
					distance[j][k] = distance[j][i] + distance[i][k];

}

void main()
{
	int center = 0;
	int road = 0;
	int i = 0;
	FILE* fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL)
	{
		puts("error");
	}

	while (!feof(fp)) {
		init();
		fscanf(fp, "%d %d", &center, &road);
		for (i = 0; i < center; i++) {
			int temp = 0;
			fscanf(fp, "%d", &temp);
			isCenter[temp - 1] = 1;
		}
		i = 0;

		while (i < road)
		{
			int fnode = 0;
			int snode = 0;
			int value = 0;
			fscanf(fp, "%d %d %d", &fnode, &snode, &value);
			if (fnode == 0 || snode == 0 || value == 0)
				break;

			fnode--;
			snode--;

			distance[fnode][snode] = value;
			distance[snode][fnode] = value;
			i++;
		}
		floyd(road, distance);


		int resultPre = DISTANCE_MAX;
		int result = -1;
		for (int i = 0; i < road; i++)
		{
			int maxOfMin = 0;
			for (int j = 0; j < road; j++)
			{
				int min = DISTANCE_MAX;
				for (int k = 0; k < road; k++)
				{
					if (isCenter[k] || i == k)
					{
						if (distance[j][k] < min)
							min = distance[j][k];
					}
				}
				if (maxOfMin < min)
					maxOfMin = min;
			}
			if (resultPre > maxOfMin)
			{
				resultPre = maxOfMin;
				result = i;
			}
		}
		if (result + 1 > 0)
			printf("%d\n", result + 1);
	}
	fclose(fp);
}
