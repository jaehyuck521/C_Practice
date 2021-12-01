#include<stdio.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define empNum 100
// description:
// author: ÀåÀçÇõ Date:2021-11-22
// first part
// this program reads the 1 file salary_v1.txt and save the data to structure arrary. and 40~49 age person's salary reduce 10% and save them to 
// file: salary_v2.txt and 30~39 age person's salary raise 20 % and save them to file: salary_v3 
// second part
// we read the salary_v1, salary_v2 from part1 and make the compare file so, we put the name, age, v1_salary and v3_ salary to compare_v1_v3.txt
// In compare_v1_v3, we put the v1_salary's sum and v3' salary's sum also. we compute them and write it to compare_v1_v3.txt
// Define employee structure
struct employee 
{
    char name[20];
    int age;
    float salary;
};
void main()
{
    FILE* fp1, * fp2, * fp3, *fp4; // for access to files
    struct employee emp[empNum];
    int i = 0, k = 0;
    float sum1, sum2 = 0;
    // read the file
    fp1 = fopen("salary_v1.txt", "r");
    // for the write of file
    fp2 = fopen("salary_v2.txt", "w");
    // defensive coding
    if (fp1 == NULL || fp2 == NULL) {
        printf("File Could Not Be Opened \n");
        exit(1);
    }
    else
    {
        // Read files
        while (fscanf(fp1, "%s  %d  %f", emp[i].name, &emp[i].age, &emp[i].salary) > 0) {
            i++;
        }
        // If employees age  40 to 49 reduce 10%
        for (k = 0; k < i; k++)
        {
            if (emp[k].age >= 40 && emp[k].age <= 49)
            {
                emp[k].salary = emp[k].salary * 0.9;
            }
        }
        // write the next input_text file
        for (k = 0; k < i; k++) 
        {
            fprintf(fp2, "%s\t%d\t%.1f\n", emp[k].name, emp[k].age, emp[k].salary);
        }
        // close the file
        fclose(fp1);
        fclose(fp2);
    }
    // read the v_2 file
    fp2 = fopen("salary_v2.txt", "r");
    // for the write of v_3 file
    fp3 = fopen("salary_v3.txt", "w");
    //defensive coding
    if (fp2 == NULL || fp3 == NULL)
    {
        printf("File Could Not Be Opened \n");
        exit(1);
    }
    else
    {
        // If employees age  30 to 39  raise 20%
        for (k = 0; k < i; k++)
        {
            if (emp[k].age >= 30 && emp[k].age <= 39)
            {
                emp[k].salary = emp[k].salary * 1.2;
            }
        }
        // write the v_3 file 
        for (k = 0; k < i; k++)
        {
            fprintf(fp3, "%s\t%d\t%.1f\n", emp[k].name, emp[k].age, emp[k].salary);
        }
        // close the file
        fclose(fp2);
        fclose(fp3);
    }
    fp1 = fopen("salary_v1.txt", "r");
    fp3 = fopen("salary_v3.txt", "r");
    fp4 = fopen("compare_v1_v3.txt", "w");
    struct employee emp1[empNum];
    struct employee emp2[empNum];
    i = 0;
    // defensive coding
    if (fp1 == NULL || fp3 == NULL)
    {
        printf("File Could Not Be Opened \n");
        exit(1);
    }
    if (fp4 == NULL)
    {
        printf("File Could Not Be Opened \n");
        exit(1);
    }
    // read the salary_v1 text file
    while (fscanf(fp1, "%s %d %f", emp1[i].name, &emp1[i].age, &emp1[i].salary) > 0)
    {
        i++;
    }
    i = 0;
    // read the salary_v3 file
    while (fscanf(fp3, "%s %d %f", emp2[i].name, &emp2[i].age, &emp2[i].salary) > 0)
    {
        i++;
    }
    // for the total salary value(v1, v3)
    sum1 = 0.0;
    sum2 = 0.0;
    for (k = 0; k < i; k++)
    {
        fprintf(fp4, "%s\t%d\t%.1f -> %.1f\n", emp1[k].name, emp1[k].age, emp1[k].salary, emp2[k].salary);
        sum1 = sum1 + emp1[k].salary;
        sum2 = sum2 + emp2[k].salary;
    }
    // write the total salary 
    fprintf(fp4,"Total : %.1f -> %.1f", sum1, sum2);
    // close the file
    fclose(fp1);
    fclose(fp3);
    fclose(fp4);
}