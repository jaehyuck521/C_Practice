#include<stdio.h>
#include<stdlib.h>
// author: ¿Â¿Á«ı date: 2021-11-17
// this program is linked list example using static allocation using array. So it's fixed length is 3 but it can extend to 5
// by structure we scan the all link and when deletekey is inserted, we scan the list and delete it from linked list
// but this circumstance when delete node is the first.
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
	struct NODE* ptr, *prev_ptr = NULL;
	struct NODE	*next_ptr = NULL;
	int delkey, deleted = 0;
	delkey = 100;
	ptr = &node[0];
	while (ptr)
	{
		if ((*ptr).key == delkey)
		{
			if (prev_ptr != NULL)
			{
				(*prev_ptr).next = (*ptr).next;
			}
			next_ptr = (*ptr).next; // saving the next node address
			(*ptr).key = -1; // get rid of from list
			(*ptr).next = NULL;
			ptr = next_ptr; //move to next
			deleted = 1;
			break;
		}
		prev_ptr = ptr;
		ptr = (*ptr).next;
	}
	if (deleted == 1)
	{
		printf("key deleted\n");
	}
	else
	{
		printf("key not founded");
	}
	ptr = &node[1]; // set new start address
	while (ptr)
	{
		printf("%d \n", (*ptr).key);
		ptr = (*ptr).next;
	}



}