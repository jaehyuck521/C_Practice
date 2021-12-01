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
    if (fp == NULL) {
        printf("File Could Not Be Opened \n");
        exit(-1);
    }
    else
    {
        while (fscanf(fp, "%s %d %s", person[i].region, &person[i].age, person[i].canVoted) > 0)
        {
            
            if (strcmp(person[i].canVoted, "Washington") == 0)
                Washington++;

            if (strcmp(person[i].canVoted, "Lincoln") == 0)
                Lincoln++;

            if (strcmp(person[i].canVoted, "Roosevelt") == 0)
                Roosevelt++;

            sum = Washington + Lincoln + Roosevelt;

            
            if (strcmp(person[i].canVoted, "Washington") == 0 && i % 3 == 0)
                thirdWashington++;

            if (strcmp(person[i].canVoted, "Lincoln") == 0 && i % 3 == 0)
                thirdLincoln++;

            if (strcmp(person[i].canVoted, "Roosevelt") == 0 && i % 3 == 0)
                thirdRoosevelt++;

            sum2 = thirdWashington + thirdLincoln + thirdRoosevelt;

          
            if (strcmp(person[i].canVoted, "Washington") == 0 && (i % 10 == 0))
                tenWashington++;

            if (strcmp(person[i].canVoted, "Lincoln") == 0 && (i % 10 == 0))
                tenLincoln++;

            if (strcmp(person[i].canVoted, "Roosevelt") == 0 && (i % 10 == 0))
                tenRoosevelt++;

            sum3 = tenWashington + tenLincoln + tenRoosevelt;

            i++;
        }
        
        fclose(fp);
    }

  
    printf("Washington : %.2f, Lincoln : %.2f, Roosevelt : %.2f \n\n",
        (Washington / sum) * 100, (Lincoln / sum) * 100, (Roosevelt / sum) * 100);

   
    printf("Sample every third row's \n");
    printf("Washington : %.2f, Lincoln : %.2f, Roosevelt : %.2f \n\n",
        (thirdWashington / sum2) * 100, (thirdLincoln / sum2) * 100, (thirdRoosevelt / sum2) * 100);

   
    printf("Sample every ten row's \n");
    printf("Washington : %.2f, Lincoln : %.2f, Roosevelt : %.2f \n\n",
        (tenWashington / sum3) * 100, (tenLincoln / sum3) * 100, (tenRoosevelt / sum3) * 100);

  
}

