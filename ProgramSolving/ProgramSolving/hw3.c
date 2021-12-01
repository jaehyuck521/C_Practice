#include<stdio.h>
#include<stdlib.h>
#define arrSize 7
#define keysSize 4
// author: ¿Â¿Á«ı date: 2021-11-17
// this program is linked list example using dynamic allocation using malloc. it crate 7 nodes of array and first 3 nodes are already in.
// they should be linked with singly linked list. And they should maintain key in ascending order. And after insert them, we print them by 
// scanList function. we need scanList function and insert key function

struct LIST 
{
    int key;
    struct LIST* next;
};
// type definition
typedef struct LIST list;
typedef list* list_ptr;

int InsertKey(list_ptr new_val_ptr, list_ptr* head);
int isEmpty(list_ptr nPtr);
void ScanList(list_ptr cur_ptr);

void main()
{
    // Insert value 
    list origin_list[arrSize];
    origin_list[0].key = 100;
    origin_list[1].key = 250;
    origin_list[2].key = 467;

    // linking
    origin_list[0].next = &origin_list[1];
    origin_list[1].next = &origin_list[2];
    list_ptr head = &origin_list[0];
    list_ptr start_list = head; // set the dummy head

    // keys
    int keys[keysSize] = {  150, 300, 50, 500};

    // new variables
    list_ptr new_list_ptr = NULL;
    list new_list[keysSize];

    for (int i = 0; i < keysSize; i++)
    {
        new_list[i].key = keys[i];
        new_list[i].next = NULL;
        new_list_ptr = &new_list[i];

        // if function  return 0 ,insert.
        // Insert new_list°Øs node (150, 300, 50, 500)
        if (InsertKey(new_list_ptr, &start_list) == 0)
        { }
        // else insert fail. 
        else
        {
            printf("%d not inserted. Key already exists. \n", keys[i]);
        }
    }
}

// Insertkey function
//A function that sorts the valu and insert it. 
//the order of values and enters it into the list
//return value = 0 -> success
//return value = 1 - >fail 
int InsertKey(list_ptr new_val_ptr, list_ptr* head)
{
    list_ptr cur = *head;
    list_ptr prev = NULL;

    while (cur != NULL) 
    {

        // if key already exists
        if (cur->key == new_val_ptr->key)
            return -1;

        // find the position
        if (cur->key > new_val_ptr->key)
            break;

        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    // if smallest value
    if (prev == NULL) 
    {
        new_val_ptr->next = *head;
        *head = new_val_ptr;
    }

    // else find the position and insert it. 
    else 
    {
        prev->next = new_val_ptr;
        new_val_ptr->next = cur;
    }

    // if insert 500, ScanList using head
    if (new_val_ptr->key == 500) 
    {
        ScanList(*head);
    }
    return 0;
}

// this function checks the empty check. 
int isEmpty(list_ptr nPtr)
{
    return nPtr == NULL;
}

// this function print the list value.
void ScanList(list_ptr cur_ptr)
{
    if (isEmpty(cur_ptr)) 
    {
        puts("List is empty.\n");
    }
    else 
    {
        puts("The list is : ");

        while (cur_ptr != NULL) 
        {
            printf("%d \n ", cur_ptr->key);
            cur_ptr = cur_ptr->next;
        }
        puts("NULL\n");
    }
}
