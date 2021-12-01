#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define votedNum 3000
#define regNum 30
#define canVotedNum 30
struct Voted {
    char region[regNum];
    int age;
    char canVoted[canVotedNum];
};
void main()
{
    int i = 0;
    double Washington = 0, Lincoln = 0, Roosevelt = 0, sum = 0;
    double thirdWashington = 0, thirdLincoln = 0, thirdRoosevelt = 0, sum2 = 0;
    double tenWashington = 0, tenLincoln = 0, tenRoosevelt = 0, sum3 = 0;
    struct Voted person[votedNum];
    // voted.txt file Opened
    FILE* fp = fopen("vote.txt", "r");
    // Use defensive coding
    if (fp == NULL) 
    {
        printf("File Could Not Be Opened \n");
        exit(-1);
    }
    else
    {
        while (fscanf(fp, "%s %d %s", person[i].region, &person[i].age, person[i].canVoted) > 0)
        {
            i++;
        }
    }
    fclose(fp);
    for (int j = 0; j < i; j++)
    {
        // printf("%s %d %s \n", person[j].region, person[j].age, person[j].canVoted);
        if (strcmp(person[j].canVoted, "Washington") == 0)
        {
            Washington++;
        }
        if (strcmp(person[j].canVoted, "Lincoln") == 0)
        {
            Lincoln++;
        }
        if (strcmp(person[j].canVoted, "Roosevelt") == 0)
        {
            Roosevelt++;
        }
       
        
    }
    printf("%.2f\n", (Washington / i) * 100);
    printf("%.2f\n", (Lincoln / i) * 100);
    printf("%.2f\n", (Roosevelt / i) * 100);





}


