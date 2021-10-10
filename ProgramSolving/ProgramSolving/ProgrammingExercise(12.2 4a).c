#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// File author: ¿Â¿Á«ı create_date=2021-9-26
// this program gets the five structure data and print the report about car
// it calculates the miles per gallon and average miles per gallon
// declare structure
struct car
{
	int carIdentifynumber;
	int miles;
	int gallons;
};
void main()
{
	// data insert
	struct car carlist[5] = {
		{25, 1450,62},{36,3240, 136},{44,1792,76},{52, 2360, 105},{68,2114, 67}
	};
	printf("Report\n");
	double sum = 0;
	// Read the data and calculate the miles per gallon and print it.
	for (int i = 0; i < 5; i++)
	{
		float medium = (double)carlist[i].miles / (double)carlist[i].gallons;
		printf("Car number: %d The miles per gallon: %f \n", carlist[i].carIdentifynumber, medium );
		sum = sum + medium;
	}
	// print the average miles per gallon
	printf("End of the report\n");
	printf("Average miles per gallon achieved by the five cars: %f", sum / 5);



}