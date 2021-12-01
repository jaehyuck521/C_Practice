#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define TRUE 1
#define FALSE 0
# define End 2
void grahamScan(struct point* P);
struct point {
	float x;
	float y;
	struct point *next;
	struct point *prev;
	float angle;
};
void main()
{
	FILE* fp;
	fp = fopen("input4.txt", 'r');

}
void grahamScan(struct point* P)
{
	struct point* firstPoint;
	struct point* tempPrev, * tempNext;

	if (P == firstPoint)
		return;
	if (!isConvexPoint(P))
	{
		tempPrev = P->prev;
		tempNext = P->next;
		tempPrev->next = tempNext;
		tempNext->prev = tempPrev;
		free(P);
		grahamScan(tempPrev);

	}
	else
		grahamScan(P->next);
}
void grahamSort()