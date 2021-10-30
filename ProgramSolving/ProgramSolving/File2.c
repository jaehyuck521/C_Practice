#include<stdio.h>
void main()
{
	int a, sum = 0;
	FILE* inFile, * outFile;
	inFile = fopen("myinFile.txt", "r");
	if (inFile == NULL)
	{
		printf("Input file could not  be opened");
		exit(1);
	}
	outFile = fopen("myoutFile.txt", "w");
	if (outFile == NULL)
	{
		printf("output file could not be opened");
		exit(1);
	}
	while (fscanf(inFile, "%d", &a) == 1)
	{
		sum = sum + a;
	}
	fprintf(outFile, "The sum is %d \n", sum);
	fclose(inFile);
	fclose(outFile);



}