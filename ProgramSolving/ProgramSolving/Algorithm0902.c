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
		fgets(pan, sizeof(pan), test); //input 읽어온다. 

		char* length = strtok(pan, " "); // 토큰화해서 가져온다. 

		while (length != NULL) {
			char* array = length;
			pancake[i] = atoi(array);
			if (pancake[i] != 0)
				printf("%d ", pancake[i]);
			length = strtok(NULL, " "); //두번째 꺼 꺼낸다.  계속 꺼낸다. 
			i++;
		}

		for (int j = i; j < pancake_size; j++)
		{
			pancake[j] = 0; //나머지는 0으로 채운다.
			zero++; // 0 의 카운트 계산
		}
		printf("\n");

		for (i = pancake_size - zero; i > 0; i--) //뒤에서 계산. 실제 값 있는 것 끼리 계산. 
		{
			max_val = 0; //flip을 위해 0으로 지정해준다. 
			for (j = 0; j < i; j++)
			{
				if (pancake[j] > pancake[max_val]) //최대 값 인덱스를 집어넣는다. 
					max_val = j;
			}

			if (max_val == i - 1)
			{
				count++; 
				continue;
			}

			if (max_val != 0) //뒤집어준다. sorting. 
			{
				printf("flip(%d) -> ", pancake_size - zero - max_val);
				flip(pancake, max_val + 1);
			}

			printf("flip(%d) -> ", count + 1); //중복되는 것에 대해 flip해준다. 
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
		// 반대편 값끼리 바꿔준다. 
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
