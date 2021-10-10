#include<stdio.h> 
int strLen(char *str);
int Search(char *str1, char *str2);
// description
// author: ¿Â¿Á«ı date:2021-10-04
// this program gets two input like example 1: they get the whole sentence and searching 2 word like ex) kim*ko and find the two
// pair of word * means between two words anything can accepted. And execute function and get the count number by scanning all
// sentence
void main()
{
    char sentence[255];
    char search[255];
    printf("Input String : ");
    gets(sentence);
    printf("Input Search String : ");
    gets(search);
    // Accept Original String and Search String!
    printf("\n");
    printf("Input String  : %s \n", sentence);
    printf("Search string  : %s \n", search);
    printf("Number of matched String : %d \n", Search(sentence, search));
    
}
// this function gets the string and return the string's length by scanning it. 
int strLen(char *str)
{
    int count = 0; // for counting
    while (str[count] != '\0') //the loop for between string starts and string ends
    {
        count++; //increment the count
    }
    return count; //return result
}
// this function gets two parameters First oridnal sentence and second is 2word and between two words is *
// So we splite the 2 word by using '*' and find the two pair of word. If we find the two word we increment count+1
// and return the count after scanning all sentence.
int Search(char *ordinal, char *search)
{ 
    int i, j, t, cnt = 0;
    char front[255], behind[255];
    int len1 = strLen(ordinal);
    int len2 = strLen(search);
    // devide them by using "*" and save to the new variable
    for (i = 0; i < len2; i++)
    {
        if (search[i] == '*')
        {
            for (j = 0; j < i; j++)
                front[j] = search[j];
            front[i] = '\0';
            for (t = 0; t < len2; t++)
            {
                behind[t] = search[t + j + 1];
                behind[t + 1] = '\0';
                if (behind[t] == '*')   // If use (*) twice -> Error! 
                    return 0;
            }

            if (search[i + 1] == '\n' || search[i + 1] == '\0')
                return 0;   // If (dong*) -> Behind String has not any String.
                            // -> Error!
        }
    } 
    // scanning and find the two word
    int len3 = strLen(front);
    int len4 = strLen(behind);
    // checking they are same or not same;
    // they maintian not zero -> match
    // they change 0  -> not match
    for (int i = 0; i < len1; i++)
    {
        int check1 = 3; // for judging find the value first word
        if (ordinal[i] == front[0]) // first search
        {
            int index = i;
            for (int j = 0; j < len3; j++)
            {
                if (ordinal[index + j] != front[j])
                {
                    check1 = 0;
                    break;
                }
            }
            if (check1 != 0) 
            {
                int check2 = 3; // for judging find the value first word
                for(int k=index+len3;k<strLen(ordinal);k++)
                { 
                    if (ordinal[k] == behind[0]) // when first matches, second search
                    {
                       
                        int index2 = k;
                        for (int j = 0; j < len4; j++)
                        {
                            if (ordinal[index2 + j] != behind[j])
                            {
                                check2 = 0;
                                break;
                            }
                            else 
                            {
                                check2 = 3;
                            }
                        }
                        if (check2 != 0)
                        {
                            cnt++;
                            break; //when find the value escape.
                        } 
                    }
                }   
            }
            
        }
    }
    return cnt;
}

