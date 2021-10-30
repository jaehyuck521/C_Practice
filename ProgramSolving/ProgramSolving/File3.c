#include<stdio.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void main()
{
	FILE *infile;
	char line[100];
	int lcount = 0;
	if ((infile = fopen("charstream.txt", "r")) == NULL)
	{
		printf("File could not be opened\n");
		exit(1);
	}
	while(*fgets(line, sizeof(line), infile)!=EOF)
	{
		lcount++;
		printf("Line %d %s", lcount, line);
	}
	fclose(infile);

}