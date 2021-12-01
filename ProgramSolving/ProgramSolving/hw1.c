#include<stdio.h>
#include<stdlib.h>
// author: ÀåÀçÇõ date: 2021-11-17
// this program is linked list example using static allocation using array. So it's fixed length is 3 but it can extend to 5
// by structure we scan the all link and when new key is inserted, we scan the list and insert it in ascending order
// but this circumstance when new node is the first.
struct NODE
{
	int key;
	struct NODE* next;
}node[5];
void main()
{
	// filling the key
	node[0].key = 100;
	node[1].key = 250;
	node[2].key = 467;
	// linking.
	node[0].next = &node[1];
	node[1].next = &node[2];
	node[2].next = NULL;
	struct NODE* ptr, * prev_ptr = NULL;
	int newkey, fail = -1;
	node[3].key = newkey = 50; // declare new key

	ptr = &node[0];
	// scanning
	while (ptr)
	{
		if ((*ptr).key > newkey) // if the first case
		{
			node[3].next = ptr;
			ptr = &node[3]; // change ptr
			prev_ptr = ptr;
			ptr = (*ptr).next;
		}
		if ((*ptr).key == newkey) // if already exists
		{
			printf("key already exists");
			break;
		}
		if ((*ptr).key < newkey) // keep scanning
		{
			prev_ptr = ptr;
			ptr = (*ptr).next;
		}
		else // when key's location found. 
		{
			(*prev_ptr).next = &node[3];
			node[3].next = ptr;
			printf("key inserted \n ");
			break;
		}
	}
	ptr = &node[3]; // start points are changed
	while (ptr)
	{
		printf("%d \n ", (*ptr).key);
		ptr = (*ptr).next;
	}


}