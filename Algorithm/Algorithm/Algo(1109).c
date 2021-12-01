#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
double javis(struct point* data, int current, int previous, int* used);
int count = 0;
int flag = 0;
int unum = 0;
int end = 0;
int skip = 0;
struct point {
	float x;
	float y;
};

void main()
{
	FILE* fp;
	fp = fopen("input5.txt", "r");
	// defensive coding
	if (fp == NULL)
	{
		puts("error");
	}
	int play = 0;
	fscanf(fp, "%d", &play);
	printf("%d\n\n", play);
	int z = 0;
	struct point* data;
	while (z < play) 
	{
		fscanf(fp, "%d", &count);
		printf("%d\n", count);
		int i = 1;
		double result = 0;
		data = (struct point*)malloc((count + 1) * sizeof(struct point));
		int* used = (int*)malloc(count * sizeof(int));
		data[0].x = 0.0;
		data[0].y = 0.0;
		while (i < count + 1)
		{
			fscanf(fp, "%f %f", &data[i].x, &data[i].y);
			printf("%.2lf %.2lf\n", data[i].x, data[i].y);
			i++;
		}
		if (count == 1)
		{
			result = 2 * (sqrt((data[i - 1].x) * (data[i - 1].x) + (data[i - 1].y) * (data[i - 1].y)));
		}
		else 
		{
			result = javis(data, 0, -1, used);
		}
		printf("%.2lf\n", result + 2); // 2 더한 것은 매듭의 길이
		z++;
		printf("\n");
		count = 0;
		flag = 0;
		end = 0;
		unum = 0;
		skip = 0;
		free(data);
	}
	fclose(fp);
}
double javis(struct point* data, int current, int previous, int* used)
{
	double min = 0, angle = 0, result = 0;
	double dx = 0, dy = 0;
	int index = -1, fflag = 0;
	for (int i = 0; i < count + 1; i++)
	{
		if (i == current || i == previous)
			continue;
		if (flag == 0)
		{
			dx = data[i].x - data[current].x;
			dy = data[i].y - data[current].y;
		}
		else if (flag == 1)
		{
			dx = -(data[i].x - data[current].x);
			dy = -(data[i].y - data[current].y);
		}
		else if (flag == 2)
		{
			dx = data[i].y - data[current].y;
			dy = -(data[i].x - data[current].x);
		}
		if ((dx >= 0) && dy >= 0)
		{
			angle = 0;
		}
		else
		{
			angle = abs(dy) / (abs(dx) + abs(dy));
			if ((dx < 0) && (dy >= 0))
			{
				angle = 2 - angle;
			}
			else if ((dx <= 0) && (dy >= 0))
			{
				angle = 2 + angle;
			}
			else if ((dx > 0) && (dy < 0))
			{
				angle = 4 - angle;
			}
		}
		if (fflag == 0)
		{
			min = angle;
			index = i;
			fflag = 1;
		}
		for (int y = 0; y < count; y++)
		{
			if (i == used[y])
				end = 1;
		}
		if (end == 1) 
		{
			if (data[current].y < 0 && data[current].x>0)
			{
				skip = 1;
			}
			end = 0;
			continue;
		}
		if (skip == 1 && data[i].y > 0) 
		{
			continue;
		}
		if (min > angle)
		{
			min = angle;
			index = i;
		}
		if (data[index].x < data[current].x && skip != 1)
			flag = 1;
		else if ((data[index].y < data[current].y) && (data[index].x <= data[current].x) && skip != 1)
			flag = 2;
		else
			flag = 0;
		result = sqrt((data[current].x - data[index].x) * (data[current].x - data[index].x) + (data[current].y - data[index].y) * (data[current].y - data[index].y));
		if (index == 0) 
		{
			result = sqrt((data[current].x) * (data[current].x) + (data[current].y) * (data[current].y));
			return result;
		}
		else
		{
			used[unum] = index;
			unum++;
			return result + javis(data, index, current, used);
		}
	}
}



