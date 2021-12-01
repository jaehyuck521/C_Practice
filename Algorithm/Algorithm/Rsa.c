#include<stdio.h>
#include<stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
void decryption(int a, int n, int c, int* x, int* y);
void binary(int k);
int euclid(int a, int b, int* x, int* y);
int result(int a, int b[], int n);
void pr(int n, int index[]);
int b[1000] = { 0, };
int index;
void main()
{
	int e = 0, n = 0, c = 0, rx = 0, ry = 0;
	FILE* fp;
	fp = fopen("input2.txt", "rt"); // read the file
	// defensive coding
	if (fp == NULL)
	{
		puts("error");
	}
	while (!feof(fp)) 
	{
		fscanf(fp, "%d %d %d", &n, &e, &c); // read public key and ciphertext c
		printf("N = %d E = %d C = %d\n", n, e, c);
		decryption(e, n, c, &rx, &ry); // decrypt
	}
	fclose(fp); //close the file
}
// extended Euclid function 
int euclid(int a, int b, int* x, int* y)
{
	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	int g = euclid(b, a % b, x, y);
	int temp1 = *y, temp2 = *x; // x prime and y prime 
	*x = temp1;
	*y = (temp2 - (int)(a / b) * temp1);
	return g;
}
// dcrypt the 
void decryption(int e, int n, int c, int* x, int* y) 
{
	int prime[2] = { 0, }; // for the save the prime number
	pr(n, prime); // prime factorizing
	int p, q, t, gcd, d;
	p = prime[0];
	q = prime[1];
	// save the p, q and compute the t
	t = (p - 1) * (q - 1);
	gcd = euclid(e, t, x, y); // get the prime to uclid function 
	d = *x;
	while (d < 0) 
	{
		d = d + t;
	}
	binary(d);
	int m=0;
	m = result(c, b, n); // get the private key by using squaring algorithm
	printf("M is  : %d \n", m);
}
// for repeated squaring algorithm with power
void binary(int k)
{
	int i = 0;
	int value = k;
	while (1)
	{
		b[i] = value % 2; // modulo
		value = value / 2; // if not zero one more computation
		if (value == 0)
		{
			break;
		}
		i++;
	}
	index = i;
}
// continued repeated squaring algorithm using above b
// Repeated squaring algorithm
int result(int a, int b[], int n)
{
	int c = 0, d = 1;
	for (int i = index; i >= 0; i--)
	{
		c = 2 * c;
		d = (d * d) % n;

		if (b[i] == 1)
		{
			c = c + 1;
			d = (d * a) % n;
		}
	}
	return d;
}
// prime factorization function 
void pr(int n, int prime[])
{
	int c = 0, k = 2;
	while (n != 1) 
	{
		if (n >= 2) 
		{
			if (n % k == 0) 
			{
				prime[c] = k; // save the divide
				c = c + 1; 
				n = n / k; // modulo zero
			}
			else 
			{
				k = k + 1; // increment the divide number
			}
		}
		else if (n < 2) // defensive coding
		{
			printf("error : cannot prime factorization \n");
		}
	}
}
