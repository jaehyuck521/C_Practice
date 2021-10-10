#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
int secs(int, int, int);
void main()
{
    int hour = 0, min = 0, sec = 0;
    printf("Press the hours ");
    scanf("%d", &hour);
    if (hour < 0) // invalide value
    {
        printf("Invalid Hours, try again ");
        scanf("%d", &hour);
    }
    printf("Press the minutes  ");
    scanf("%d", &min);
    if (min < 0) //in valid value
    {
        printf("Invalid Minutes, try again ");
        scanf("%d", &min);
    }
    printf("Press the seconds  ");
    scanf("%d", &sec);
    if (sec < 0)  // invalid value
    {
        printf("Invalid Seconds, try again ");
        scanf("%d", &sec);
    }
    printf("Total second is : %d \n", secs(hour, min, sec));
    
}
int secs(int hour, int min, int sec) 
{

    int totSec = 0;
    totSec = (hour * 3600) + (min * 60) + sec;
    return totSec;

}


