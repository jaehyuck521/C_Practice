#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define pancake_size 30

void flip(int, int); //declare
void main()
{
	FILE* test = fopen("input.txt", "rt");
	int caseNum = 1;

	if (test == NULL)
	{
		puts("error");
	}

	while (!feof(test)) {

		char pan[100] = { 0 , };
		int i = 0, count = 0, max_val, j, zero = 0;
		int pancake[pancake_size];

		printf("Delicious pancakes Case %d : ", caseNum);
		fgets(pan, sizeof(pan), test); //input �о�´�. 

		char* length = strtok(pan, " "); // ��ūȭ�ؼ� �����´�. 

		while (length != NULL) {
			char* array = length;
			pancake[i] = atoi(array);
			if (pancake[i] != 0)
				printf("%d ", pancake[i]);
			length = strtok(NULL, " "); //�ι�° �� ������.  ��� ������. 
			i++;
		}

		for (int j = i; j < pancake_size; j++)
		{
			pancake[j] = 0; //�������� 0���� ä���.
			zero++; // 0 �� ī��Ʈ ���
		}
		printf("\n");

		for (i = pancake_size - zero; i > 0; i--) //�ڿ��� ���. ���� �� �ִ� �� ���� ���. 
		{
			max_val = 0; //flip�� ���� 0���� �������ش�. 
			for (j = 0; j < i; j++)
			{
				if (pancake[j] > pancake[max_val]) //�ִ� �� �ε����� ����ִ´�. 
					max_val = j;
			}

			if (max_val == i - 1)
			{
				count++; 
				continue;
			}

			if (max_val != 0) //�������ش�. sorting. 
			{
				printf("flip(%d) -> ", pancake_size - zero - max_val);
				flip(pancake, max_val + 1);
			}

			printf("flip(%d) -> ", count + 1); //�ߺ��Ǵ� �Ϳ� ���� flip���ش�. 
			count++;
			flip(pancake, i);
		}
		printf("flip(0)\n\n");
		caseNum++;
	}
}

void flip(int* pan, int num)
{
	int temp;
	int i;
	for (i = 0; i < --num; i++) {
		// �ݴ��� ������ �ٲ��ش�. 
		printf("%d %d \n", i, num);
		temp = pan[i];
		pan[i] = pan[num];
		pan[num] = temp;
	}
	for (i = 0; i < pancake_size; i++)
	{
		if (pan[i] == 0)
			continue;
		printf("%d ", pan[i]);
	}
	printf("\n");
}
