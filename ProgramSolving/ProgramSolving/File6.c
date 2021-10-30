#include<stdio.h>
#include<stdlib.h>

#define nameLen 20
#define carNum 4


struct CAR 
{
    char name[nameLen];
    int year;
    float price;
} car[carNum];

void main()
{
    int i = 0;
    struct CAR car[carNum] = {
      {"Avante", 2007, 13000.00},
      {"Sonata", 2008, 18000.00},
      {"SM7", 2009, 22000.00},
      {"Equus", 2010, 35000.00}
    };

    FILE* fp;
    fp = fopen("cars.txt", "w");
    if (fp == NULL)
    {
        printf("File Could not be Opened \n");
        exit(1);
    }
    else
    {
        fprintf(fp, "|Name   |Year   |Price       | \n");
        fprintf(fp, "------------------------------ \n");
        for (i = 0; i < 4; i++)
        {
            fprintf(fp, "|%-7s|%d   |%.2f    |\n", car[i].name, car[i].year, car[i].price);
        }
        fprintf(fp, "------------------------------ \n");
        fclose(fp);
    }
    fp = fopen("cars.txt", "r");
    if (fp == NULL)
    {
        printf("File Could not be Opened \n");
        exit(1);
    }
    else
    {
        char ch;
        while (1)
        {
            ch = fgetc(fp);
            if (ch == EOF)
                break;
            putchar(ch);
        }
    }
}
