#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void secs(int, int*, int*, int*, int*);
void main()
{
    int hour = 0, min = 0, sec = 0;
    int total = 0;
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
    secs(&hour, &min, &sec, &total);
    printf("The total second is: %d ", total);




}
void secs(int *hour, int *min, int *sec, int *totSec)
{
    int h = *hour;
    int m = *min;
    int s = *sec;
    *totSec = (h * 3600) + (m * 60) + s;
  
}