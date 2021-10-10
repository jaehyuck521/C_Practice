#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<stdio.h>
// author:¿Â¿Á«ı date:2021-09-26
//this program gets 2 array day, month, day from user. And stores the recent days structure to other variable
// Ex) the recent date is stored later variable call by reference.
struct Date	// Define struct date
{
    int month;
    int day;
    int year;
};
void recent();
// get the valid data from user.
void main()
{
    struct Date d[2];
    struct Date later;
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Type the %d's year : ", i+1);
        scanf("%d", &d[i].year);
        if (d[i].year < 1) {
            printf("Retype the year : ");
            scanf("%d", &d[i].year);
        }

        printf("Type the %d's month : ",i+1);
        scanf("%d", &d[i].month);
        if (d[i].month < 1 || d[i].month > 12) {
            printf("Retype  the month : ");
            scanf("%d", &d[i].month);
        }

        printf("Type  the %d's day : ", i+1);
        scanf("%d", &d[i].day);
        if (d[i].day < 1 || d[i].day > 31) {
            printf("Retype the day : ");
            scanf("%d", &d[i].day);
        }
        printf("\n");
    }
    recent(d, &later);
    printf("The recent date is : %d/%d/%d \n", later.month, later.day, later.year);
}
// this function gets 2 array structure and judge what is recent date between 2 array data and store recent date arrays to other struct variable 
// It is call by reference function
void recent(struct Date d[] ,struct Date *fast)
{
    if (d[0].year < d[1].year) // compare the year
    {
        *fast = d[1];
    }
    else if (d[0].year == d[1].year) // when year is same, compare the month
    {
        if (d[0].month < d[1].month)
        {
            *fast=d[1];
        }
        else if (d[0].month == d[1].month) // when year and month is same, compare the days.
        {
            if (d[0].day < d[1].day)
            {
                *fast=d[1];
            }
            else
            {
                *fast=d[0];
            }
        }
        else
        {
            *fast=d[0];
        }
    }
    else
    {
        *fast=d[0];
    }
}
