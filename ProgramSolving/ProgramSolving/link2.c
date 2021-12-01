#include<stdio.h>
#include<stdlib.h>
// author: ¿Â¿Á«ı date: 2021-11-10
// this program is linked list example using static allocation using array. So it's fixed length is 3
// by structure, we use next and linking them by next variable. And we give the the search key. they search the key following the order,
// if found, print the found message or not found print the not found message. 
// structure
struct NODE {
	int key;
	struct NODE* next;
}node[3];
void main()
{
	// by distinguishing mode found or not found
	int check = 0;
	int search = 0;
	// filling the key
	node[0].key = 100;
	node[1].key = 250;
	node[2].key = 467;
	// linking.
	node[0].next = &node[1];
	node[1].next = &node[2];
	node[2].next = NULL;
	// pointer variable
	struct NODE *nodeptr;
	nodeptr = &node[0]; // get the start pointer address.
	// get the key by user
	printf("Press the search key: ");
	scanf("%d", &search);
	printf("Our search key is %d \n", search);
	while (nodeptr) // searching
	{
		if ((*nodeptr).key == search)
		{
			printf("Found!!");
			check = 1;
			break;
		}
		nodeptr = (*nodeptr).next; // move to next. 
	}
	if (check == 0)
	{
		printf("Not found!!");
	}





}