#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void strcopy(char str1[],char str2[]); //declare the function
void main()
{
	char fp[100] = "abcde"; 
	char ep[100]="klmno"; //initialize and variables
	//char fp[100]="abc";
	//char ep[100]="xyz";

	printf("Before\n"); //print the before executing function
	printf("%s", fp);
	strcopy(fp, ep); //execute function
	printf("\n");
	printf("After \n"); //print the result after executing function
	printf("%s", fp);


	
}
void strcopy(char string1[], char string2[]) //the function that copy the char array to char array
{
	int i = 0; 
	while (string1[i] != '\0') //when char array ends
	{
		string1[i] = string2[i]; //copy the string2 to string1
		i = i + 1; //increment the i
	}
	string1[i] = '\0';  // insert the \0 to last element.

}