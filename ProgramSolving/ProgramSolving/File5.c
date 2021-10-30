#include <stdio.h>
#include <stdlib.h>
struct CAR
{
	char name[20];
	int year;
};
void main()
{
	struct CAR car[2] = {
		{"Avante", 2007},
		{"Sonata", 2008} 
	};
	FILE* file;
	char str[100];
	file = fopen("cars.txt", "w");
	if (file == NULL)
	{
		printf("cars.txt cannot be opened.\n");
		exit(1);
	}
	for (int i = 0; i < 2; i++)
	{
		fprintf(file, "%s %d\n", car[i].name, car[i].year);
	}
	fclose(file);
	file = fopen("cars.txt", "r");
	if (file == NULL)
	{
		printf("cars.txt cannot be opened.\n");
		exit(1);
	}
	while (fgets(str, sizeof(str), file) != NULL)
	{
		printf(str);
	}
	fclose(file);

}