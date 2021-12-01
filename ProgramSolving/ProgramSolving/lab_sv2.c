#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Vote {
	char region[20];
	int age;
	char candidate[20];
};
void main()
{
    FILE* fp = fopen("vote.txt", "r");
    int i = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int sum = 0;
    int num = 0;
    struct Vote person[2000];
    // Use defensive coding
    if (fp == NULL)
    {
        printf("File Could Not Be Opened \n");
        exit(-1);
    }
    else
    {
        while (fscanf(fp, "%s %d %s", person[i].region, &person[i].age, person[i].candidate) > 0)
        {
            i++;
            num++;
        }
        for (int j = 0; j < i; i++)
        {
            if (strcmp(person[j].candidate, "Washington") == 0)
            {
                count1++;
            }
            if (strcmp(person[j].candidate, "Lincoln") == 0)
            {
                count2++;
            }
            if (strcmp(person[j].candidate, "Rossevelt") == 0)
            {
                count3++;
            }
        }
        printf("%d %d \n", num, count1);
        printf("the average is %.2f", (count1 / num) * 100);
    }
    






}