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
		scanf("%s %s", start[i], end[i]); //�ð� �Է¹޴´�. ���� �ð�, ������ �ð�
		gets_s(app[i], sizeof(app[i])); //���ڿ� �Է� �޴´�. ���� Ȱ������.
		strcpy(dumb_s, start[i]); //���� �ð��� ����. 
		token = strtok(dumb_s, delimit); //���� �ð��� �ɰ��� �ð��� ������,
		hour = atoi(token); //����ȯ
		token = strtok(NULL, delimit); //����� ���� �����ڸ� �����´�. ����
		min = atoi(token); //�� ��ȯ. char to integer 
		if (hour < 10 || hour>18 || min < 0 || min >= 60) { //���� ����. 
			i--;
			printf("error! time is wrong! 10<=hh<=18  00<=min<60\n");
			printf("enter again!\n");
			continue;
		}
		strcpy(dumb_e, end[i]); // ������ �ð��� �����´�. 
		token = strtok(dumb_e, delimit); //�и�
		hour = atoi(token); //����ȯ
		token = strtok(NULL, delimit); //���� �Ű������� �����´�.
		min = atoi(token); //����ȯ. 
		if (hour < 10 || hour>18 || min < 0 || min >= 60) { //üũ
			i--;
			printf("error! time is wrong! 10<=hh<=18  00<=min<60\n");
			printf("enter again!\n");
			continue;
		}
	}

	//�غ� ��
	//sorting in chronological order
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num - 1; j++)
		{
			if (strcmp(start[j], start[j + 1]) > 0) //�ٷ� �ڿ� �Ŷ� ��.
			{
				strcpy(temp_h, start[j]);
				strcpy(start[j], start[j + 1]);
				strcpy(start[j + 1], temp_h); //�ٲ۴�. ������.
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
		puts(app[i]); //��� �Լ�. 
	}


	for (i = 0; i < num; i++) //for saving the original variable(start,end)
	{
		strcpy(i_start[i], start[i]);
		strcpy(i_end[i], end[i]);
	}

	//calculate each durations
	for (i = 0; i < num - 1; i++)
	{
		token = strtok(end[i], delimit); //���� �ð� �����´�.
		eh = atoi(token); // �� ��ȯ
		token = strtok(NULL, delimit); //���� �������� ����
		em = atoi(token); //����ȯ
		total_e = eh * 60 + em; //�� �ð��� ���Ѵ�. �� �м��� ���Ѵ�. 

		token = strtok(start[i + 1], delimit); //���� ���� �ð��� �����´�.
		sh = atoi(token);
		token = strtok(NULL, delimit);
		sm = atoi(token);
		total_s = sh * 60 + sm; //�� �м��� �����´�.
		dur[i] = total_s - total_e; //�߰��� �� �ð��� ����Ѵ�. �迭��. 
	}

	//find the max duration
	int max = dur[0]; //�ʱⰪ�� �����´�. 
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
