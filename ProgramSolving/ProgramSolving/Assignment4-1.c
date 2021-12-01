#include<stdio.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// author: ¿Â¿Á«ı date:2021-11-22
// this program gets the character from user, and the program convert it to binary format. 
// ex) if a is pressed, 01100001 is printed.  binary number
void main()
{
	char ch = "";
	printf("Press the character: ");
	scanf("%c", &ch); // get the alphabet from user;
	int i = 0;
	int arr[8]; // for the saving binary num
	int mask=0x80; // the mask
	printf("%c\n", ch);
	while (i < 8) // iterate and compare with mask 
	{
		if ((ch & mask) != 0) // if find the 1 value of it. and save it to array
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 0;
		}
		mask = mask >> 1; // right shift the mask
		i = i + 1; // increment value
	}
	// print the array value 
	for (int j = 0; j < 8; j++)
	{
		printf("%d ", arr[j]);
	}

}