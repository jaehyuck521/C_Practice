#include <stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void main()
{
    int maxage = -1; 
    int minage = 1000;
    int maxscore = -1, minscore = 1000;
    int maxagecnt, minagecnt, maxscorecnt, minscorecnt=0;
    int age[5], score[5];
    int maxagegrp[5], minagegrp[5];
    int maxscoregrp[5], minscoregrp[5];
    int i=0;
    // variables
    while(i<5) //get the input age & score 5
    {
        printf("Enter the age and score!!!:  ");
        scanf("%d", &age[i]); //get the age
        scanf("%d", &score[i]); //get the score
        if (age[i] <= 0 || score[i] < 0) // for the invalid value like negative number
        {
            i=i-1; // for the valid value
            printf("It is invalid value \n"); //print that the value are invalid
        }
        i = i + 1;
    }
    for (i = 0; i < 5; i++) 
    {
         if (age[i] > maxage) //finding max age
        {
            maxage = age[i];
            maxagecnt = 0;
            maxagegrp[maxagecnt] = i; //for the redundant value
        }
        else if (age[i] == maxage)  // the case that multiple max age.
        {
            maxagecnt = maxagecnt + 1; //increment the count
            maxagegrp[maxagecnt] = i; // save the index
        }
    }
    for (i = 0; i < 5; i++) // for the case age cannot be below zero, and score should be larger than -1
    {
         if (age[i] < minage) // finding minimum of age
        {
            minage = age[i];
            minagecnt = 0;
            minagegrp[minagecnt] = i; //for redundant data of min age
        }
        else if (age[i] == minage) // if there are redundant data min age,
        {
            minagecnt = minagecnt + 1; //increment minage count
            minagegrp[minagecnt] = i; //save the index
        }
    }
    for (i = 0; i < 5; i++)  //finding max score
    {
        
         if (score[i] > maxscore)  //finding process for max score
        {
            maxscore = score[i];
            maxscorecnt = 0;
            maxscoregrp[maxscorecnt] = i; //for redundant data of max score
        }
        else if (score[i] == maxscore) //if there are redundant max score, increment the count and save the index
        {
            maxscorecnt = maxscorecnt + 1;
            maxscoregrp[maxscorecnt] = i;
        }
    }
    for (i = 0; i < 5; i++) // finding the minscore 
    {
        if (score[i] < minscore) //finding the min score
        {
            minscore = score[i];
            minscorecnt = 0;
            minscoregrp[minscorecnt] = i; //for redundant min score
        }
        else if (score[i] == minscore) // if there are multiple value of minscore
        {
            minscorecnt = minscorecnt + 1; // increment the count
            minscoregrp[minscorecnt] = i; // save the index of redundant data
        }
    }
    for (i = 0; i <= maxagecnt; i++) //print the max age student's score
    {
        printf("Score for an oldest student = %d\n", score[maxagegrp[i]]);
    }

    for (i = 0; i <= minagecnt; i++)  //print the min age student's score
    {
        printf("Score for an youngest student = %d\n", score[minagegrp[i]]);
    }

    for (i = 0; i <= maxscorecnt; i++)  //print the max score student's age
    {
        printf("Age for an max score student = %d\n", age[maxscoregrp[i]]);
    }
    for (i = 0; i <= minscorecnt; i++)  //print the min score student's age
    {
        printf("Age for an min score student = %d\n", age[minscoregrp[i]]);
    }

   
}
