#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// File author:¿Â¿Á«ı date: 2021-09-16
// This program gets float arrays and show the array components by using function.For using function we 
// print the array components
void show(float*, int);
void main()
{
    float rates[8] = {6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.8, 10.0};

    int length = sizeof(rates) / sizeof(float); //calcualte the length of array.
    show(rates, length);
}
// the function that accepts the array and array length, and print the array. 
void show(float* rates, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%f \n ", rates[i]);
    }
}

