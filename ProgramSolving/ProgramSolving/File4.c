#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i;
	FILE* myFile;
	myFile = fopen("myinFile.txt", "r");
	if (myFile == NULL)
	{
		printf("\n File Could Not be Opened");
	}
	else
	{
		char ch = fgetc(myFile);
		while (ch != EOF)
		{
			putchar(ch);
			ch = fgetc(myFile);

		}
		printf("\nFinished printing the file\n");
		fclose(myFile);
	}



}