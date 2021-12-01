#include<stdio.h>
#include<stdlib.h>
// author: ¿Â¿Á«ı date: 2021-11-10
// this program is linked list basic struction practice. we declare the separate struct NODE data nodes and assign the address of node1
// to next of node 0 linking the nodes.
struct NODE {
	int key;
	struct NODE* next;
};
void main()
{
	// declare the struct nod datanodes
	struct NODE *node0, * node1, * node2;
	node0 = (struct NODE*)malloc(sizeof(struct NODE));
	node1 = (struct NODE*)malloc(sizeof(struct NODE));
	node2 = (struct NODE*)malloc(sizeof(struct NODE));
	if (node0 != NULL && node1 !=NULL && node2 !=NULL) //defensive coding
	{
		(*node0).key = 100;
		(*node1).key = 200;
		(*node2).key = 300;
		(*node0).next=node1;
		(*node1).next=node2;
		(*node2).next = NULL;
	}
	// free the memory allocation
	free(node0);
	free(node1);
	free(node2);
	




}