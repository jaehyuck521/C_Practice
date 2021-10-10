#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
int character_count(char str[]); //declare the function
void main()
{
	char test[100] = "hoypark"; //the test data
	int answer; //for the answer
	answer = character_count(test); //execute the function
	printf("Original data : %s", test);
	printf("\n"); 
	printf("The count of %s %d",test, answer); //print the result


}
int character_count(char str[])
{
	int count = 0; // for counting
	while (str[count] != '\0') //the loop for between string starts and string ends
	{
		count++; //increment the count
	}
	return count; //return result
}