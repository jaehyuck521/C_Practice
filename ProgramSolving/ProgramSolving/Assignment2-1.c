#include <stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// Author:¿Â¿Á«ı Date:201-10-04 
//This program finds the string data from sentence. First we insert two sentence Full sentence and the word that we wanted to find
// we use variable char array. and execute function.
int exactmatch(char * a, char * b);
int strlen(char* str);
// declare function
void main()
{
    //inputs
    char s1[200] = "A thief named hong gil dong lived with friends named hong gildonand hong gil jaand hhhong gil dongand kong gil dongandhonggil dongand hong gil donggg in a village named hong gil dong village.";
    char s2[20] = "hong gil dong";
    char s3[40] = "I am humourous person and person";
    char s4[20] = "person";
    char s5[40] = "I am humourouse persoa";
    char s6[20] = "person";
    char s7[40] = "I am jaehyuck";
    char s8[20] = "jae";
    char s9[40] = "we are the future.";
    char s10[20] = "future";
    printf("sentence: %s", s1);
    printf("\nSearching word: %s", s2);
    printf("\n The exact match count is: ");
    printf("%d\n", exactmatch(s1, s2));
    printf("sentence: %s", s3);
    printf("\nSearching word: %s", s4);
    printf("\n The exact match count is: ");
    printf("%d\n", exactmatch(s3, s4));
    printf("sentence: %s", s5);
    printf("\nSearching word: %s", s6);
    printf("\n The exact match count is: ");
    printf("%d\n", exactmatch(s5, s6));
    printf("sentence: %s", s7);
    printf("\nSearching word: %s", s8);
    printf("\n The exact match count is: ");
    printf("%d\n", exactmatch(s7, s8));
    printf("sentence: %s", s9);
    printf("\nSearching word: %s", s10);
    printf("\n The exact match count is: ");
    printf("%d\n", exactmatch(s9, s10));
}
// this function gets two input full sentence and searching word. First, in sentence we find the search word's first character
// we compare all word. if the matches we increment count number. After scanning all sentence return the count
int exactmatch(char * sentence, char * search)
{
    int count = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == search[0])
        {
            int index = i; // save the index
            int check = 1; // for they are match or not. 
            for (int j = 0; j<strlen(search); j++) // scanning the word and sentence
            {
                if (sentence[index + j] != search[j])
                {
                    check = 0;
                    break;
                }
            }
            i = i + strlen(search);
            if (check == 1)
            {
                count++;
            }
        }
    }
    return count;
}
int strcmp(char* arr1, char* arr2) 
{
    int i = 0;
    while (arr1[i] != '\0' || arr2[i] != '\0')
    {
        if (arr1[i] > arr2[i])
        {
            return 1;
        }
        else if (arr1[i] < arr2[i])
        {
            return 1;
        }
        i++;
    }
    return 0;      
}
// this function input is char pointer and calculate string's length and return the length
int strlen(char * str)
{
    int count = 0; // for counting
    while (str[count] != '\0') //the loop for between string starts and string ends
    {
        count++; //increment the count
    }
    return count; //return result
}