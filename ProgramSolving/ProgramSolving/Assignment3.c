#include<stdio.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// description
// author: ÀåÀçÇõ date:2021-10-28
// this program reads the text data by using file pointer and save the contents to array. And we read first number and the number is components of group and
// divide the group and print the group component's number and their average. 
void main()
{
    int arr[18] = { 0 }; // variables
    int i = 0;
    int j, groupdivide = 0, y = 0;
    float sum[3] = { 0,0,0 };
    // open the text file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("File Could Not Be Opened \n");
        exit(1);
    }
    else
    {
        while (fscanf(file, "%d", &arr[i]) > 0) // read the data and save it to array. 
        {
            i++;
        }
        fclose(file); // close the file
    }
    i = 0;
    // for the debug
    //for (int i = 0; i < 18; i++)
   // {
     //   printf("%d ", arr[i]);
   // }
    // groupdivide is a group number 
    // sum = Each Group's sum of the components for the average
    while(i<18)
    {
        groupdivide+= arr[i];
        for (j = i + 1; j < groupdivide + 1; j++)
        {
            sum[y] += arr[j];
        }
        printf("%d Group Average : %.2f \n", arr[i], sum[y] / arr[i]);
        y++;
        i = groupdivide + 1;
        groupdivide++;
    }

   
}
