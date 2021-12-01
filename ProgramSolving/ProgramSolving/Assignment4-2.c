#include<stdio.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// author: ¿Â¿Á«ı date: 2021-11-22
// this program prints the integer with various format, first left is decimal number and second one is binary number lastly third one is hexadecimal number
// it iterates 1000 times ex) 10 1010 A

void main()
{
	int bina[20] = { 0 };
	int pos = 0; // for the array pos
	for (int i = 1; i < 1001; i++) // iterates 1~1000
	{
		printf("DEC %d: ", i); //print decimal
		int num = i;
		while (1) // for the binary conversion
		{
			bina[pos] = num % 2; // save the binary 1 or zero value
			num = num / 2; // for iterates
			pos++; 
			if (num == 0) // end condition 
			{
				break;
			}
		}
		printf("BIN  ");
		for (int j = pos - 1; j >= 0; j--) // print reversely 
		{
			printf("%d", bina[j]);
		}
		char hex[20] = {0}; // for saving the hexadecmial number
		pos = 0; // reset the pos
		num = i; //reset the number
		int mod = 0; // for the remainder
		while (1)
		{
			mod = num % 16; //compute the modular
			if (mod < 10)
			{
				hex[pos] = 48 + mod; // for the char '1' 
			}
			else
			{
				hex[pos] = 65 + (mod - 10); // for the char 'A' to 'F'
			}
			num = num / 16; // iterate
			pos++;
			if (num == 0) // end condition
			{
				break;
			}

		}
		printf(" HEX ");
		for (int z = pos - 1; z >= 0; z--) // print it reversely 
		{
			printf("%c", hex[z]);
		}
		printf("\n");
	}
}








