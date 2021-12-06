#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define dateLen 20
#define feeLen 5
#define nameLen 25
#define orgLen 35
#define jobLen 15
#define peoNum 30

#define MAXLINE
struct PEOPLE {
    int tag;
    char date_regi[dateLen];
    char fee_paid[feeLen];
    char name[nameLen];
    int age;
    char organization[orgLen];
    char job[jobLen];
    struct PEOPLE* next;
}people[peoNum], * sorted_ppl[peoNum], check[peoNum];

int Read_FileLine();

void Read_File(struct PEOPLE* infoList);

void StoreInLink(struct PEOPLE* infoList);

void PrintLinkedList(struct PEOPLE* LinkedList);

void PrintArray(struct PEOPLE* Array);

struct PEOPLE* NodeMalloc(int size);

int Update(struct PEOPLE* infoList, struct PEOPLE* updatedList); // Mark P7-1 P7-2

int checksum(struct PEOPLE* updatedList); //8-1

void DeleteLink(struct PEOPLE* nodeList); // Mark P6-2
void DeleteArray(); // Mark P6-1
void Sort_data_in_age(); // Mark P4-1
void List_using_sorted(struct PEOPLE* nodeList); // Mark P5-1

void search_name_in_array(int*); // 1-1
void search_name_in_linkedlist(struct PEOPLE* nodeList); //1-2
void search_organization_job_in_array(int*); //2-1
void search_organization_job_in_linkedlist(struct PEOPLE* nodeList); //2-2
void sort_data_in_tag(int*); //3-1


int main(void)
{
    int line = Read_FileLine();


    struct PEOPLE* infoList;



    infoList = NodeMalloc(line);

    Read_File(infoList);

    Read_File(people);

    StoreInLink(infoList);

    struct PEOPLE* nodeList;
    nodeList = (struct PEOPLE*)malloc(line * sizeof(struct PEOPLE));
    Read_File(nodeList);
    StoreInLink(nodeList);
    search_name_in_array(&line);
    search_name_in_linkedlist(nodeList);
    search_organization_job_in_array(&line);
    search_organization_job_in_linkedlist(nodeList);
    sort_data_in_tag(&line);

    Sort_data_in_age();
    List_using_sorted(nodeList);
    DeleteArray();
    DeleteLink(nodeList);
    struct PEOPLE* updatedList;
    updatedList = NodeMalloc(line + 1);


    Update(infoList, updatedList);

    for (int i = 0; i <= 30; i++)
    {
        printf("%s\n", (updatedList[i]).name);
    }

    printf("\nThe checksum value is : %d", checksum(updatedList));
    printf("\nThe checksum value '1' means that checksum matches.");

    free(updatedList);
    free(infoList);
    free(nodeList);


    return 0;
}

int Read_FileLine()
{
    struct PEOPLE readFile;
    int i = 0;

    // registration_data.txt file open
    // read the structrue and form
    FILE* fp;
    fp = fopen("registration_data.txt", "r");

    // Use defensive coding
    if (fp == NULL)
    {
        printf("File Could not be Opened \n");
        exit(1);
    }
    else
    {
        i = 0;
        while (fscanf(fp, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &readFile.tag, readFile.date_regi, readFile.fee_paid, readFile.name, &readFile.age, readFile.organization, readFile.job) > 0)
        {
            i++;
        }
        // registration_data.txt closed
        fclose(fp);
        return i;
    }
}

void Read_File(struct PEOPLE* infoList)
{
    int i = 0;

    // registration_data.txt file open
    // read the structrue and form
    FILE* fp;
    fp = fopen("registration_data.txt", "r");

    // Use defensive coding
    if (fp == NULL)
    {
        printf("File Could not be Opened \n");
        exit(1);
    }
    else
    {
        i = 0;
        while (fscanf(fp, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &infoList[i].tag, infoList[i].date_regi, infoList[i].fee_paid, infoList[i].name, &infoList[i].age, infoList[i].organization, infoList[i].job) > 0)
        {
            i++;
        }
        // registration_data.txt closed
        fclose(fp);
    }
}

/*
description: store the data in a linked list
output: void
*/
void StoreInLink(struct PEOPLE* infoList)
{
    int i = 0;
    // Adress initialize
    while (infoList[i + 1].tag > 0)
    {
        infoList[i].next = &infoList[i + 1];
        i++;
    }
    infoList[i].next = NULL;
}

void PrintLinkedList(struct PEOPLE* LinkedList)
{
    printf("\n===== Show linked list =====\n");
    struct PEOPLE* begin;
    begin = &LinkedList[0];
    while (begin->tag > 0)
    {
        printf("%d/", begin->tag);
        printf("%s/", begin->date_regi);
        printf("%s/", begin->fee_paid);
        printf("%s/", begin->name);
        printf("%d/", begin->age);
        printf("%s/", begin->organization);
        printf("%s \n", begin->job);

        begin = begin->next;
    }

}

void PrintArray(struct PEOPLE* Array)
{
    printf("\n===== Show array =====\n");
    int i = 0;
    while (Array[i].tag > 0)
    {
        printf("%d/", Array[i].tag);
        printf("%s/", Array[i].date_regi);
        printf("%s/", Array[i].fee_paid);
        printf("%s/", Array[i].name);
        printf("%d/", Array[i].age);
        printf("%s/", Array[i].organization);
        printf("%s \n", Array[i].job);

        i++;
    }

}

/*
Description:Search for "Kim"(if found, print all information about the person)
*In the array
*output: void
*author:parkchuljong
*/

void search_name_in_array(int* length) {
    int i;
    printf("===== Search for Kim (P1_1) =====\n");
    for (i = 0; i <= *length; i++)
    {
        if (strstr(people[i].name, "Kim") != NULL)
        {
            printf("%s: %d/%s/%s/%d/%s/%s\n", people[i].name, people[i].tag, people[i].date_regi, people[i].fee_paid,
                people[i].age, people[i].organization, people[i].job);
        }

    }

}
/*
Description:Search for "Kim"(if found, print all information about the person)
*In the linked list
*output: void
*author:parkchuljong
*/
void search_name_in_linkedlist(struct PEOPLE* nodeList) {
    struct PEOPLE* ptr = &nodeList[0];
    ptr = ptr->next;
    printf("===== Search for Kim (P1_2) =====\n");
    while (ptr)
    {
        if (strstr(ptr->name, "Kim") != NULL)
        {
            printf("%s: %d/%s/%s/%d/%s/%s\n", ptr->name, ptr->tag, ptr->date_regi, ptr->fee_paid,
                ptr->age, ptr->organization, ptr->job);
        }
        ptr = ptr->next;
    }

}
/*
Description:Search for engeineer from Gachon University(if found, print all information about the person)
*In the array
*output: void
*author:parkchuljong
*/
void search_organization_job_in_array(int* length) {
    int i;
    printf("===== Search for engeineer from Gachon University (P2_1) =====\n");
    for (i = 0; i <= *length; i++)
    {
        if (strstr(people[i].organization, "Gachon University") != NULL && strstr(people[i].job, "engineer") != NULL)
        {
            printf("%s: %d/%s/%s/%s/%d/%s\n", people[i].organization, people[i].tag, people[i].date_regi, people[i].fee_paid,
                people[i].name, people[i].age, people[i].job);
        }

    }
}
/*
Description:Search for engeineer from Gachon University(if found, print all information about the person)
*In the linked list
*output: void
*author:parkchuljong
*/
void search_organization_job_in_linkedlist(struct PEOPLE* nodeList) {
    struct PEOPLE* ptr = &nodeList[0];
    ptr = ptr->next;
    printf("===== Search for engeineer from Gachon University (P2_2) =====\n");
    while (ptr)
    {
        if (strstr(ptr->organization, "Gachon University") != NULL && strstr(ptr->job, "engineer") != NULL)
        {
            printf("%s: %d/%s/%s/%s/%d/%s\n", ptr->organization, ptr->tag, ptr->date_regi, ptr->fee_paid, ptr->name,
                ptr->age, ptr->job);
        }
        ptr = ptr->next;
    }

}
/*
Description:Sort the data in the array in tag# order
*Using bubble sort algorithm
*output: void
*author:parkchuljong
*/
void sort_data_in_tag(int* length) {
    struct PEOPLE* ppl[peoNum], temp;
    int i, j;
    printf("===== Sort the data in the array in tag# order (P3_1) =====\n");
    for (i = 0; i < *length; i++)
        ppl[i] = &people[i];

    for (i = 0; i < *length - 1; i++) {
        for (j = 0; j < *length - i - 1; j++)
        {
            if (ppl[j]->tag > ppl[j + 1]->tag)
            {
                temp = *ppl[j];
                *ppl[j] = people[j + 1];
                *ppl[j + 1] = temp;
            }
        }


    }
    for (i = 0; i < *length; i++)
    {
        printf("%d/%s/%s/%s/%d/%s/%s\n", ppl[i]->tag, ppl[i]->date_regi,
            ppl[i]->fee_paid, ppl[i]->name, ppl[i]->age, ppl[i]->organization, ppl[i]->job);

    }

}


/*
Description:Sort the data in the array in age group order
*Using selection sort algorithm
*output: void
*author : choijaekyung
*/

void Sort_data_in_age() {
    struct PEOPLE temp, temp2;
    int i;
    int least;
    int tempnum;
    for (i = 0; i < peoNum; i++) {
        //sorted_ppl[i] = &people[i];
        //printf("%d/%s/%s/%s/%d/%s/%s\n",people[i].tag,people[i].date_regi,people[i].fee_paid,people[i].name
                          //              ,people[i].age,people[i].organization,people[i].job);
    }
    for (i = 0; i < peoNum; i++) {
        sorted_ppl[i] = &people[i];
        //printf("%d/%s/%s/%s/%d/%s/%s\n",sorted_ppl[i]->tag,sorted_ppl[i]->date_regi,sorted_ppl[i]->fee_paid,sorted_ppl[i]->name
                                      //  ,sorted_ppl[i]->age,sorted_ppl[i]->organization,sorted_ppl[i]->job);
    }

    for (i = 0; i < peoNum - 1; i++)
    {
        least = i;

        for (int j = i + 1; j < peoNum; j++)
        {
            if ((sorted_ppl[least]->age) > (sorted_ppl[j]->age))
            {
                least = j;

            }
        }
        if (least != i)
        {
            temp = people[i];
            temp2 = people[least];
            *sorted_ppl[least] = temp;
            *sorted_ppl[i] = temp2;
        }
    }

    printf("===== Selection Sort (P4_1) =====\n");

    for (int i = 0; i < peoNum; i++)
    {

        printf("%d/%s/%s/%s/%d/%s/%s\n", sorted_ppl[i]->tag, sorted_ppl[i]->date_regi, sorted_ppl[i]->fee_paid, sorted_ppl[i]->name
            , sorted_ppl[i]->age, sorted_ppl[i]->organization, sorted_ppl[i]->job);
    }

    FILE* myFile;
    myFile = fopen("4-1.txt", "w");
    if (myFile == NULL)
        printf("\nFile Could Not Be Opened");
    else
    {
        for (int i = 0; i < peoNum; i++)
        {

            fprintf(myFile, "%d/%s/%s/%s/%d/%s/%s\n", sorted_ppl[i]->tag, sorted_ppl[i]->date_regi, sorted_ppl[i]->fee_paid, sorted_ppl[i]->name
                , sorted_ppl[i]->age, sorted_ppl[i]->organization, sorted_ppl[i]->job);
        }
        fclose(myFile);
        printf("file print success\n");
    }
}

/*
Create a new linked list using the sorted data
*output: void
*author: choijaekyung
*/
void List_using_sorted(struct PEOPLE* nodeList)
{
    printf("===== Linked list using sorted array (P5_1) =====\n");
    int i, j = 1;

    for (i = 0; i < peoNum; i++)
    {
        nodeList[i] = *sorted_ppl[i];
    }
    for (i = 0; i <= peoNum; i++)
    {
        nodeList[i].next = NULL;
    }
    for (i = 0; i <= peoNum - 1; i++)
    {
        nodeList[i].next = &nodeList[i + 1]; //connect node
    }
    nodeList[peoNum - 1].next = NULL; //last node's next is null
    struct PEOPLE* head = NULL; //make head node
    head = &nodeList[0];
    struct PEOPLE* curr = head;

    printf("\nlinked list\n");
    while (curr != NULL)
    {
        printf("current node is %d  ", j);
        printf("%d/%s/%s/%s/%d/%s/%s\n", curr->tag, curr->date_regi, curr->fee_paid, curr->name, curr->age, curr->organization, curr->job);
        curr = curr->next;
        j++;
    }
    for (i = 0; i < peoNum; i++)
    {
        //printf("%d/%s/%s/%s/%d/%s/%s\n",node[i].tag,node[i].date_regi ,node[i].fee_paid,node[i].name,node[i].age,node[i].organization,node[i].job);
    }

}

/*
*Description: delete the data in a struct array
*In the array
*Output: void
*Author : kimtaewoo
*/

void DeleteArray() {// Mark P6-1
    int i, h, l;

    for (i = 29; i >= 0; i--) {
        if (strstr(people[i].name, "Kim") != NULL) {
            for (h = i; h <= peoNum; h++) {
                people[h].age = people[h + 1].age;
                people[h].tag = people[h + 1].tag;
                for (l = 0; l < 30; l++)
                    people[h].date_regi[l] = people[h + 1].date_regi[l];
                for (l = 0; l < 30; l++)
                    people[h].fee_paid[l] = people[h + 1].fee_paid[l];
                for (l = 0; l < 30; l++)
                    people[h].name[l] = people[h + 1].name[l];
                for (l = 0; l < 30; l++)
                    people[h].organization[l] = people[h + 1].organization[l];
                for (l = 0; l < 30; l++)
                    people[h].job[l] = people[h + 1].job[l];
            }
        }
    } //deleting Kim's data
    printf("===== Delete data from the array (P6_1) =====\n");

    for (i = 0; people[i].tag != NULL; i++) {
        printf("%d %d/%s/%s/%s/%d/%s/%s\n", i + 1, people[i].tag, people[i].date_regi, people[i].fee_paid, people[i].name, people[i].age, people[i].organization, people[i].job);

    }
}


/*Description: delete the data in a linked list
*In the linked list
*Output: void
*Author : kimtaewoo
*/

void DeleteLink(struct PEOPLE* nodeList) {// Mark P6-2
    printf("===== Delete data from the Linked list (P6_2) =====\n");
    int i;


    nodeList = nodeList->next;

    while (nodeList)
    {
        if (strstr(nodeList->name, "Kim") == NULL)//deleting Kim's data
        {
            printf("%s: %d/%s/%s/%s/%d/%s\n", nodeList->name, nodeList->tag, nodeList->date_regi, nodeList->fee_paid, nodeList->name,
                nodeList->age, nodeList->job);
        }
        nodeList = nodeList->next;
    }
}

struct PEOPLE* NodeMalloc(int size) // Function that allocate memory.
{
    struct PEOPLE* memory;
    memory = (struct PEOPLE*)malloc(size * sizeof(struct PEOPLE));
    if (memory == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    else
        return memory;
}


int Update(struct PEOPLE* infoList, struct PEOPLE* updatedList) // Function that updates for "Gildong Kang"
{
    FILE* NewGuest;
    struct PEOPLE NewGuest_Info;
    NewGuest = fopen("New_Registeration.txt", "r");
    if (NewGuest == NULL)
    {
        printf("Can't find the data to update.\n");
        return -1;
    }
    // Defensive code
    else
    {
        // Read new guest
        if (fscanf(NewGuest, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &NewGuest_Info.tag, NewGuest_Info.date_regi, NewGuest_Info.fee_paid, NewGuest_Info.name, &NewGuest_Info.age, NewGuest_Info.organization, NewGuest_Info.job) > 0)
        {
            printf("New Guest detected!\n");
            printf("Guest information.\n");
            printf("%d/ ", NewGuest_Info.tag);
            printf("%s/ ", NewGuest_Info.date_regi);
            printf("%s/ ", NewGuest_Info.fee_paid);
            printf("%s/ ", NewGuest_Info.name);
            printf("%d/ ", NewGuest_Info.age);
            printf("%s/ ", NewGuest_Info.organization);
            printf("%s ", NewGuest_Info.job);
            printf("\n");

            // If guest have no tag, give him apropriate tag number
            if (NewGuest_Info.tag = -1)
            {
                printf("Tag missing!\n");
                printf("Giving right tag...\n");
                // Find new tag that hasn't used already
                int i = 0;
                int temp = 0;
                while (infoList[i].tag > 0)
                {
                    if (temp <= infoList[i].tag)
                    {
                        temp = infoList[i].tag;
                    }
                    i++;
                }
                NewGuest_Info.tag = temp + 1;
                // Show given tag number
                printf("Tag has been given! (%d)\n", NewGuest_Info.tag);
            }

        }


        // Mark P7-1
        // Add in to the array
        int i = 0;

        // Find list size
        while (infoList[i].tag > 0)
        {
            updatedList[i] = infoList[i];
            i++;
        }

        updatedList[i] = NewGuest_Info;

        // Selection sorting.

        for (int j = 0; j <= i - 1; j++)
        {
            int kMin = j;
            for (int k = j + 1; k <= i; k++)
            {
                if (updatedList[k].age <= updatedList[kMin].age)
                {
                    kMin = k;
                }
            }

            if (kMin != j)
            {
                struct PEOPLE temp;
                temp = updatedList[j];
                updatedList[j] = updatedList[kMin];
                updatedList[kMin] = temp;
            }
        }

        // Mark P7-2
        // Add in to linked list
        for (int n = 0; n <= i; n++)
        {
            updatedList[n].next = NULL;
        }
        for (int n = 0; n < i; n++)
        {
            updatedList[n].next = &updatedList[n + 1];
        }
        fclose(NewGuest);

        printf("\n===== Data list (P7) =====\n\n");
        struct PEOPLE* begin;
        begin = &updatedList[0];

        while (begin)
        {
            printf("%d/", begin->tag);
            printf("%s/", begin->date_regi);
            printf("%s/", begin->fee_paid);
            printf("%s/", begin->name);
            printf("%d/", begin->age);
            printf("%s/", begin->organization);
            printf("%s \n", begin->job);

            begin = begin->next;
        }
        printf("===== End Of List =====\n");
        return 1;
    }
}



/*Mark 8-1
Description: compute the org_checksum and copy_checksum, then compare that.
*output: return value (0 or 1)
*author : Jang jae hyuk, Min jung won(modify)
*/
int checksum(struct PEOPLE* updatedList) // recent data
{
    int i = 0;
    int nameStr;
    int org_checksum = 0;
    int copy_checksum = 0;
    char fin[5][20]; // for the name value
    int n = 0;
    while (updatedList[n].tag > 0)
        n++;
    for (int j = n - 5; j <= n - 1; j++) // most recent 5 name data and compute the checksum
    {
        nameStr = strlen(updatedList[j].name);
        org_checksum = org_checksum ^ nameStr;
        strcpy(fin[i], (updatedList[j]).name); // get the name for saving to file
        i++;
    }

    FILE* fp1;
    fp1 = fopen("8-1.txt", "w");
    if (fp1 == NULL)
    {
        printf("\nFile Could Not Be Opened");
        exit(1);
    }
    fprintf(fp1, "%d", org_checksum);
    for (int a = 0; a <= 4; a++) // write most recent 5
    {
        fprintf(fp1, "\n%s", fin[a]); // write the name from fin
    }
    //8-1.txt file closed//
    fclose(fp1);

    FILE* fp3;
    fp3 = fopen("8-1.txt", "r"); // read the file
    // Use defensive coding
    if (fp3 == NULL)
    {
        printf("File Could not be Opened \n");
        exit(1);
    }
    i = 0;
    char temp[20];
    while (!feof(fp3)) // recompute the checksum from file
    {
        fgets(temp, 20, fp3);
        if (i == 0) // first line we will pass because it's checksum
        {
            i++;
        }
        else  // for second line, we calculate checksum;
        {
            nameStr = strlen(temp);
            copy_checksum = copy_checksum ^ nameStr;
            i++;
        }
    }

    // if orginal checksum differ copied checksum return 1 (success)
    // if orginal checksum equal copied checksum return 0  (fail)
    if (org_checksum != copy_checksum)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
