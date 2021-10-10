#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// author:¿Â¿Á«ı date:2021-09-16
// this program gets three arrays price and quantity and amount. We use  function the extend function
// So program fills the amount variables by using price and quantity variables. and print the amount array's 
// components.
// declare the function
void extend(double*, double*, double*); // declare
void main()
{
    double price[10] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
    double quantity[10] = { 4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8};
    double amount[10] = {0};
    // variables
    //execute function and print the result
    extend(price, quantity, amount);
    for(int i = 0; i < 10; i++)
    {
        printf("Amout : %d : %f \n",i, amount[i]);
    }
}
// the function that gets address of array and multipy price array's value and quantitiy array's value and save the
// result to the amount arrays. 
void extend(double  *price, double *quantity, double  *amount)
{
    for (int i = 0; i < 10; i++)
    {
        amount[i] = price[i] * quantity[i];
    }
}
