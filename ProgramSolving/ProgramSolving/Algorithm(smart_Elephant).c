#include <stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
int count = 0;
struct data 
{
	int num;
	int wt;
	int smart;
};
void main()
{
	int i = 0, temp = 0;
	char elephant[100] = { 0 , };
	FILE* file = fopen("input.txt", "rt"); //for read file
	if (file == NULL)
	{
		puts("error invalid input!!!!"); //if file not exists print error.
	}
	while (!feof(file)) // Get the count of all input. 
	{
		fgets(elephant, sizeof(elephant), file);
		count++;
	}
	struct data* sdata;
	sdata = (struct data*)malloc(count * sizeof(struct data)); // dynamic allocation
	fseek(file, 0, SEEK_SET); // move to file first

	while (!feof(file)) 
	{

		int check = 0; // distinguisher
		fgets(elephant, sizeof(elephant), file); // Read the input file
		char* input = strtok(elephant, " ");  // get the input of elephant
		while (input != NULL)
		{
			char* array = input;
			if (check == 0) // for the weight
			{
				sdata[i].num = i + 1;
				sdata[i].wt = atoi(array); //save the data
				check = 1;
			}
			else if (check == 1) // for the smart
			{
				sdata[i].num = i + 1;
				sdata[i].smart = atoi(array);// save the data
				check = 0;
			}
			input = strtok(NULL, " "); //move to the next line
		}
		i++;
	}
	// scan the data & sorting
	for (i = 0; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// swap the data
			if (sdata[j].wt > sdata[i].wt)
			{
				temp = sdata[i].num;
				sdata[i].num = sdata[j].num;
				sdata[j].num = temp;

				temp = sdata[i].wt;
				sdata[i].wt = sdata[j].wt;
				sdata[j].wt = temp;

				temp = sdata[i].smart;
				sdata[i].smart = sdata[j].smart;
				sdata[j].smart = temp;
			}
			
			else if (sdata[j].wt == sdata[i].wt)
			{
				if (sdata[j].smart > sdata[i].smart)
				{
					// swap the data
					temp = sdata[i].num;
					sdata[i].num = sdata[j].num;
					sdata[j].num = temp;

					temp = sdata[i].wt;
					sdata[i].wt = sdata[j].wt;
					sdata[j].wt = temp;

					temp = sdata[i].smart;
					sdata[i].smart = sdata[j].smart;
					sdata[j].smart = temp;
				}
			}
		}
	}
	//If the earlier elephant's smart is higher than selected one(by for loop), can make sequence.
	int degree[100];
	int prev[100];
	for (int i = 0; i < count; i++)
	{
		degree[i] = 1;
		prev[i] = -1;
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sdata[i].wt == sdata[j].wt)
				continue;
			if (sdata[j].smart > sdata[i].smart)
			{
				if (degree[j] + 1 > degree[i])
				{
					degree[i] = degree[j] + 1;
					prev[i] = j;
				}
			}
		}
	}
	// find the longest the sequence
	int max = 0;
	for (i = 0; i < count; i++)
	{
		max = 0;
		if (degree[i] > degree[max])
		{
			max = i;
		}
	}
	printf("%d \n", degree[max]);
	temp = 0;
	int result[100];
	while (max != -1)
	{
		result[temp] = sdata[max].num;
		max = prev[max];
		temp++;
	}
	// print the sequence
	printf("The sequence is below here \n");
	for (i = temp - 1; i >= 0; i--)
	{
		printf("%d \n", result[i]);
	}
	free(sdata); // free the dynamic allocation
	fclose(file); //close the file
}
