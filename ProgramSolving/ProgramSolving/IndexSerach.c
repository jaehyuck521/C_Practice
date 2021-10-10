#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<stdio.h>
#include <string.h>
//description: This program is find the data from index table. Index is Name value. So
// we press the name and index you can see the other value hobby and age. 
struct People { // Define People struct
    char name[10];
    int age;
    char hobby[20];
} p[5] = {
    {"Kim", 39, "Tennis"},
    {"Ko", 15, "Soccer"},
    {"Lee", 17, "Soccer"},
    {"Choi", 21, "Tennis"},
    {"Park", 10, "Tennis"}
};
struct Index {  // Define Index struct and Connect the struct People
    char name[10];
    struct People* p; // get the address of struct array.
} idx[5] = {
  {"Kim",  &p[0]},
  {"Ko",   &p[0]},
  {"Lee",  &p[0]},
  {"Choi", &p[0]},
  {"Park", &p[0]},
};
void SearchIndex();
void main()
{
    char searchName[10];
    int index = 0;
    printf("List of people - DataSet \n");	
    for (int i = 0; i < 5; i++)
    {
        printf("%d %s %d %s \n", i, p[i].name, p[i].age, p[i].hobby); // display the dataset
    }
    printf("\n");

    printf("Index Search: press name and array index : ");		//  Search peoeple
    scanf("%s %d", searchName, &index);
    SearchIndex(searchName, index);

    printf("Index Search: Press name and array index : ");		// Search
    scanf("%s %d", searchName, &index);
    SearchIndex(searchName, index); 
}
// the function finds the data using two parameter Name, index
// first, we compare search name and index table's name. and we print the other information struct array's data
void SearchIndex(char* searchName, int i)	// Accept Search name and Index Number;
{
    if (strcmp(searchName, idx[i].name) == 0)	// Compare
    {
        printf("%s %d %s \n", idx[i].name, idx[i].p[i].age, idx[i].p[i].hobby);
    }
    else
        printf("  Wrong Name! or Wrong Index \n");
}

