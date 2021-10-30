#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
struct vertex_info
{
	float x;
	float y;
	int index;
};
struct Wegiht_node
{
	int vertex1;
	int vertex2;
	double cost;
};
int num = 0;

void union_(int belongs[], int no1, int no2);
int find(int belongs[], int vertex);
void main()
{
	printf("Implement by Kruskal's algorithm\n");
	struct vertex_info vertex[100];
	struct Wegiht_node weight[100];
	int h = 0, n = 0;
	int i = 0, j = 0;
	scanf("%d", &h); //no.rumtime
	for (n = 0; n < h; n++)
	{
		if (h)
		{
			printf("\n");
		}
		scanf("%d", &num); //no.dot
		for (i = 0; i < num; i++)
		{
			scanf("%f%f", &vertex[i].x, &vertex[i].y); //x axis and y axis data
			vertex[i].index = i;
		}
		double w[100][100] = { 0, };
		double temp1 = 0, temp2 = 0;
		int k = 0;
		// Calculating the weight of dot.
		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{

				if (vertex[i].x == vertex[j].x) // x axis is same
				{
					w[i][j] = vertex[i].y - vertex[j].y;
					if (w[i][j] < 0)
					{
						w[i][j] = -(w[i][j]);
					}
				}
				else if (vertex[i].y == vertex[j].y) // y axis is same
				{
					w[i][j] = vertex[i].x - vertex[j].x;
					if (w[i][j] < 0)
					{
						w[i][j] = -(w[i][j]);
					}
				}
				else //using Pythagoras' algorithm
				{
					if (vertex[i].y - vertex[j].y < 0 || vertex[i].x - vertex[j].x < 0)
					{
						temp1 = (vertex[i].y - vertex[j].y) * (vertex[i].y - vertex[j].y) + (vertex[i].x - vertex[j].x) * (vertex[i].x - vertex[j].x);
						w[i][j] = sqrt(temp1);
					}
					else
					{
						temp2 = (vertex[i].y - vertex[j].y) * (vertex[i].y - vertex[j].y) + (vertex[i].x - vertex[j].x) * (vertex[i].x - vertex[j].x);
						w[i][j] = sqrt(temp2);
					}
				}
				weight[k].vertex1 = i;
				weight[k].vertex2 = j;
				weight[k].cost = w[i][j];
				k++;
			}
		}
		int temp = 0;
		//sorting the weight 
		for (i = 0; i < k - 1; i++)
		{
			for (j = 0; j < k - 1 - i; j++)
			{
				if (weight[j].cost > weight[j + 1].cost)
				{
					temp1 = weight[j].cost;
					weight[j].cost = weight[j + 1].cost;
					weight[j + 1].cost = temp1;

					temp = weight[j].vertex1;
					weight[j].vertex1 = weight[j + 1].vertex1;
					weight[j + 1].vertex1 = temp;


					temp = weight[j].vertex2;
					weight[j].vertex2 = weight[j + 1].vertex2;
					weight[j + 1].vertex2 = temp;

				}
			}
		}
		int no1, no2;
		double total = 0;
		int belongs[100];
		// make the set.
		for (i = 0; i < num; i++)
		{
			belongs[i] = i;
		}
		for (i = 0; i < k; i++)
		{
			no1 = find(belongs, weight[i].vertex1);
			no2 = find(belongs, weight[i].vertex2);
			if (no1 != no2)
			{
				total = total + weight[i].cost;
				union_(belongs, no1, no2);
			}
		}
		printf("%.2f\n", total);
	}
	
}
//this function is used for making the set, using belongs array. At first, belongs array is initialized with all different number.get the set by using vertex
int find(int belongs[], int vertex)
{
	return(belongs[vertex]);
}

// this function is used for making the union. If two vertex are in the same set, then the vertex in belongs array have same data.
void union_(int belongs[], int no1, int no2)
{
	int i = 0;
	for (i = 0; i < num; i++) //making the union
	{
		if (belongs[i] == no2)
		{
			belongs[i] = no1;
		}
	}
}
