#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// author: ?????? create-date:2021-09-21
// this program get the year, month, day from user and 
// using this date data from user, calculate the whole days 
// supposing the year is 360 days month is 30 days. 
// structure
struct Date
{
	int month;
	int day;
	int year;
};
int Days();
void main()
{
    struct Date d= {0,0,0};
    printf("Type the year : ");
    scanf("%d", &d.year);
    if (d.year < 2000)
    {
        printf("Retype the year : ");
        scanf("%d", &d.year);
    }
    printf("Type the month : ");
    scanf("%d", &d.month);
    if (d.month <= 0 || d.month > 12) 
    {
        printf("Retype the month : ");
        scanf("%d", &d.month);
    }
    printf("Type the day : ");
    scanf("%d", &d.day);
    if (d.day <= 0 || d.day > 31) 
    {
        printf("Retype the day : ");
        scanf("%d", &d.day);
    }
    // get the date daa from user
    printf("Total number of days : %d \n", Days(d));
}
// this function that calculating whole days by structure date data. and return whole days. call by value function
// 1 year:360 days. 1 month: 30 days.
int Days(struct Date d)	
{				
    int totalDay = 0;
    totalDay = (360 * (d.year - 2000)) + (30 * (d.month - 1)) + (d.day - 1);
    return totalDay;
}
