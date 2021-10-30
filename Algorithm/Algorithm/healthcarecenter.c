#include<math.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
struct path
{
	int start;
	int end;
	int cost;
};
void main()
{
	int n1, n2 = 0;
	int i1, i2, cost = 0;
	struct path map[100];
	scanf("%d %d", &n1, &n2);
	int h[100] = { 0 };
	for (int i = 0; i < n2; i++)
	{
		printf("Press the health center location please \n");
		scanf("%d", h[i]);
	}
	printf("Press the health center location \n");
	for(int i=0; i<n2;i++)
	{
		printf("Press the path \n");
		scanf("%d %d %d ", &i1, &i2, &cost);
		map[i].start = i1;
		map[i].end = i2;
		map[i].cost = cost;
		if (i1 < 0 || i2 < 0 || cost < 0)
		{
			break;
		}
	}
	for (int j = 0; j < n2; j++)
	{
		if(map[j].start== h[j])


	}






}