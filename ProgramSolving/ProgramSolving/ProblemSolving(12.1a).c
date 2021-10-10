#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
struct User {
	int month;
	int day;
	int year;
};
void main()
{
	struct User u1;
	printf("Press the Year ");
	scanf("%d", &u1.year);
	printf("Press the Month ");
	scanf("%d", &u1.month);
	printf("Press the Day ");
	scanf("%d", &u1.day);
	printf("Complete date: %d - %d -%d ", u1.year, u1.month, u1.day);

}