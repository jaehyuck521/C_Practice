#include<stdio.h>
#include<string.h>
#define day 3
char start[100][6], end[100][6], app[100][255]; 
void main()
{
	
	char i_start[100][6], i_end[100][6];
	char dumb_s[6], dumb_e[6];
	char temp_a[30], temp_h[6], temp_m[6];
	int dur[99] = {0};
	int i, j, num, hour, min;
	int sh, sm, eh, em, total_s, total_e;
	char* token;
	char delimit[] = ":";

	printf("Enter the number of schedules: ");
	scanf("%d", &num);
	while (num > 100)
	{
		printf("error! schedules should be less than 100!!\n");
		scanf("%d", &num);
	}

	printf("Enter the details in each line\n");
	for (i = 0; i < num; i++)
	{
		scanf("%s %s", start[i], end[i]); //시간 입력받는다. 시작 시간, 마지막 시간
		gets_s(app[i], sizeof(app[i])); //문자열 입력 받는다. 무슨 활동인지.
		strcpy(dumb_s, start[i]); //시작 시간을 복사. 
		token = strtok(dumb_s, delimit); //시작 시간을 쪼갠다 시간과 분으로,
		hour = atoi(token); //형변환
		token = strtok(NULL, delimit); //지우면 다음 구분자를 가져온다. 분을
		min = atoi(token); //형 변환. char to integer 
		if (hour < 10 || hour>18 || min < 0 || min >= 60) { //제약 조건. 
			i--;
			printf("error! time is wrong! 10<=hh<=18  00<=min<60\n");
			printf("enter again!\n");
			continue;
		}
		strcpy(dumb_e, end[i]); // 마지막 시간을 가져온다. 
		token = strtok(dumb_e, delimit); //분리
		hour = atoi(token); //형변환
		token = strtok(NULL, delimit); //다음 매개변수를 가져온다.
		min = atoi(token); //형변환. 
		if (hour < 10 || hour>18 || min < 0 || min >= 60) { //체크
			i--;
			printf("error! time is wrong! 10<=hh<=18  00<=min<60\n");
			printf("enter again!\n");
			continue;
		}
	}

	//준비 끝
	//sorting in chronological order
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num - 1; j++)
		{
			if (strcmp(start[j], start[j + 1]) > 0) //바로 뒤에 거랑 비교.
			{
				strcpy(temp_h, start[j]);
				strcpy(start[j], start[j + 1]);
				strcpy(start[j + 1], temp_h); //바꾼다. 순서를.
				strcpy(temp_m, end[j]);
				strcpy(end[j], end[j + 1]);
				strcpy(end[j + 1], temp_m);
				strcpy(temp_a, app[j]);
				strcpy(app[j], app[j + 1]);
				strcpy(app[j + 1], temp_a);
			}
		}
	}

	//show the sorted schedules
	printf("\nTIME LINE: \n");
	for (i = 0; i < num; i++)
	{
		printf("%s %s ", start[i], end[i]);
		puts(app[i]); //출력 함수. 
	}


	for (i = 0; i < num; i++) //for saving the original variable(start,end)
	{
		strcpy(i_start[i], start[i]);
		strcpy(i_end[i], end[i]);
	}

	//calculate each durations
	for (i = 0; i < num - 1; i++)
	{
		token = strtok(end[i], delimit); //끝난 시간 가져온다.
		eh = atoi(token); // 형 변환
		token = strtok(NULL, delimit); //분을 가져오기 위해
		em = atoi(token); //형변환
		total_e = eh * 60 + em; //총 시간을 구한다. 총 분수를 구한다. 

		token = strtok(start[i + 1], delimit); //다음 시작 시간을 가져온다.
		sh = atoi(token);
		token = strtok(NULL, delimit);
		sm = atoi(token);
		total_s = sh * 60 + sm; //총 분수를 가져온다.
		dur[i] = total_s - total_e; //중간에 빈 시간을 계산한다. 배열로. 
	}

	//find the max duration
	int max = dur[0]; //초기값을 가져온다. 
	int count = 0, final = 0;
	for (i = 1; i < num - 1; i++)
	{
		if (max < dur[i]) {
			max = dur[i];
			count++;
			final = count;
		}
		if (max == dur[i])//if the duration is same, then earlist is to be max
		{
			count++;
			continue;
		}
	}

	//output
	printf("\n\n");
	if (max >= 60)
		printf("day #%d: the longest nap starts at %s and will last for %d hours %d minutes.", day, i_end[final], max / 60, max % 60);
	else if (max < 60)
		printf("day #%d: the longest nap starts at %s and will last for %d minutes.", day, i_end[final], max);
	
}
