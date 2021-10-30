#include<stdio.h>
void main()
{
	int i;
	FILE *myFile;
	double price[2] = { 139.25,19.03 };
	char description[][20] = {"glove","CD" };
	myFile = fopen("price.dat", "w");
	if (myFile == NULL)
	{
		printf("\nFile could Not Be Opened");
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			fprintf(myFile, "%-9s %6.2f\n", description[i], price[i]);
			fclose(myFile);
		}
	}

}