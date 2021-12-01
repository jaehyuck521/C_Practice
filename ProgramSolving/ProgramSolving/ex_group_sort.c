// ex_group.c : Lab-G (with Ordering). grouping by the bubble sorting.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define DEBUG

#include <stdio.h>
#include <string.h>

#define MAXNUM 30

// struct for the person data
struct PERSON {
	char name[20];
	int age;
	char hobby[20];
};

// function prototype
void init_struct(struct PERSON[]);
void read_data(char[], struct PERSON[], int*);
void sort_by_age(struct PERSON[], int);
void sort_by_hobby(struct PERSON[], int);
void write_results(char[], struct PERSON[], int);

void main() {
	//declaration	
	int n_persons = 0;

	struct PERSON person[MAXNUM];

	// filenames
	char inFilename[] = "personal.txt";
	char outFilename_age[] = "age.txt";
	char outFilename_hobby[] = "hobby.txt";

	init_struct(person);
#ifdef DEBUG
	printf("\ninit_struct is done.\n");
#endif // DEBUG

	read_data(inFilename, person, &n_persons); // read data
#ifdef DEBUG
	printf("\nread_data is done.\n");
#endif // DEBUG

	sort_by_age(person, n_persons); // age group
#ifdef DEBUG
	printf("\nsort_by_age is done.\n");
#endif // DEBUG

	write_results(outFilename_age, person, n_persons); // write age.txt
#ifdef DEBUG
	printf("\nwrite_results for the age group is done.\n");
#endif // DEBUG

	sort_by_hobby(person, n_persons); // hobby group
#ifdef DEBUG
	printf("\nsort_by_hobby is done.\n");
#endif // DEBUG

	write_results(outFilename_hobby, person, n_persons); //write hobby.txt
#ifdef DEBUG
	printf("\nwrite_results for the hoddy group is done.\n");
#endif // DEBUG
}

void init_struct(struct PERSON per[]) {
	for (int i = 0; i < MAXNUM; i++) {
		// person 
		per[i].name[0] = '\0'; 
		per[i].hobby[0] = '\0';
	}
}

void read_data(char finename[], struct PERSON per[], int* n_persons) {
	int n = 0;
	FILE* inFile = NULL;

	inFile = fopen(finename, "r");
	if (inFile == NULL) {
		printf("\nInput File Could Not Be Opened.\n");
		return;
	}

	while (fscanf(inFile, "%s %d %s", per[n].name, &per[n].age, per[n].hobby) == 3) {
#ifdef DEBUG
		printf("% s % d % s\n", per[n].name, per[n].age, per[n].hobby);
#endif
		n++;
	}
	*n_persons = n;

	if (inFile != NULL) {
		fclose(inFile);
		inFile = NULL;
#ifdef DEBUG
		printf("\nInput File for Person Has Been Closed.\n");
#endif // DEBUG		
	}
}

void swap(struct PERSON* a, struct PERSON* b) {
	struct PERSON tmp = *a;
	*a = *b;
	*b = tmp;
}

// bubble sort
void sort_by_age(struct PERSON per[], int n) {
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			if (per[j].age > per[i].age)
				swap(&per[j], &per[i]);
		}
	}
}

// bubble sort
// https://www.geeksforgeeks.org/sorting-strings-using-bubble-sort-2/
void sort_by_hobby(struct PERSON per[], int n) {
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			if (strcmp(per[j].hobby, per[i].hobby) > 0)
				swap(&per[j], &per[i]);
		}
	}
}


void write_results(char finename[], struct PERSON per[], int n) {
	FILE* outFile = NULL;
	outFile = fopen(finename, "w");

	if (outFile == NULL) {
		printf("\nError age: Output FileCould Not Be Opened.\n");
		return;
	}

	for (int i = 0; i < n; i++)
		fprintf(outFile, "%s %d %s\n", per[i].name, per[i].age, per[i].hobby);

	if (outFile != NULL) {
		fclose(outFile);
		outFile = NULL;
#ifdef DEBUG
		printf("\nOutput File Has Been Closed.\n");
#endif // DEBUG			
	}
}