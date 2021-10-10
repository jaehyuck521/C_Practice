#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define MAX 100
#define alph_num 26

// Tree node
typedef struct node
{
	char alphabet;  // for aplphabet
	int freq; //frequency
	struct node* left; // left child node
	struct node* right; // right child node
}node;

node* make_Huffman_tree(char arr[]);  // make the Hauffman Tree
node* makenode(char alphabet, int freq, struct node* left, struct node* right); // for the new node
void make_table(node* n, char str[], int len, char* table[]); // make the variable length per alphabet
void decode(char* str, node* root); // decode function
node node_arr[alph_num] = { NULL };
int ind = 0; // number of character.

// Create new node node includes alphabet info & frequency and left right child node info. 
node* makenode(char alphabet, int freq, struct node* left, struct node* right)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->alphabet = alphabet;
	new_node->freq = freq;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}
// Create the Hauffman code tree (compress the character)
node* make_Huffman_tree(char arr[])
{
	int i = 0;
	int j;
	int temp_n = 0;
	int min = 0;  // Lowest frequncy
	int min2 = 0; // the Second lowest frequency
	int fre[alph_num] = { 0 };  // alphabet frequency 
	int check[alph_num] = { 0 };  
	node* tree[alph_num] = { NULL };  // Compare nod array
	node* new_node; // new node
	while (arr[i] != NULL)
	{
		//calculate the array. 
		fre[arr[i] - 'A']++;
		i++;
	}
	for (int i = 0; i < alph_num; i++) // iterate with alphabet number.
	{
		// if exists.
		if (fre[i] != 0)
		{
			node_arr[ind] = *makenode(i + 'A', fre[i], NULL, NULL);
			tree[ind++] = makenode(i + 'A', fre[i], NULL, NULL); // create node. 
		}
	}
	// find the lowest frequency node. 
	for (i = 0; i < ind - 1; i++)
	{
		j = 0;
		while (check[j] == -1)	j++; 
		min = j;

		for (j = min; j < ind - 1; j++) // check the all 
			if (check[j] != -1) 
				if (tree[min]->freq > tree[j]->freq)
					// if find the minimum frequency node.
					min = j;

		// find the second lowest frequncy nod.
		j = 0;
		while (check[j] == -1 || j == min) j++;
		min2 = j;  
		for (j = min2; j < ind; j++)
			if (check[j] != -1) 
				if (tree[min2]->freq > tree[j]->freq)
					// get the second lowest frequency
					if (j != min) // but not the lowest
						min2 = j;
		tree[min] = makenode(NULL, tree[min]->freq + tree[min2]->freq, tree[min], tree[min2]);
		// using sum of min and secondest min frequency .
		check[min2] = -1;
	}
	return tree[min]; 
}
// Create the varialbe length per alphabet
//(트리 루트 노드,가변 길이 코드 문자열,문자열에 들어갈 위치, 저장 될 배열)
void make_table(node* n, char str[], int len, char* table[])
{
	if (n->left == NULL && n->right == NULL) // leaf node.
	{
		str[len] = '\0'; 
		strcpy(table[(n->alphabet) - 'A'], str);
	}
	else // not leaf node
	{
		if (n->left != NULL) // the case left child
		{
			str[len] = '0'; // insert 0
			make_table(n->left, str, len + 1, table);
		}
		if (n->right != NULL) //the case right child
		{
			str[len] = '1'; // insert 1
			make_table(n->right, str, len + 1, table);
			
		}
	}
}

// Decode function it needs character and root node. 
void decode(char* str, node* root)
{
	int i = 0;
	node* j = root;
	while (str[i] != '\0') 
	{
		if (str[i] == '0') // if the zero move to left
			j = j->left;
		else if (str[i] == '1') // if the 1 move to right
			j = j->right; 
		if (j->left == NULL && j->right == NULL) // leafnode
		{
			printf("%c", j->alphabet); // print the value of leaf node.
			j = root;
		}
		i++;
	}
	printf("\n");
}


int main()
{
	char arr[MAX]; 
	char* code[alph_num]; 
	char str[MAX]; 
	char encoding[MAX] = ""; 
	int i; 
	char answer; 
	node* root;//트리의 루트
	for (i = 0; i < alph_num; i++)
		code[i] = (char*)malloc(sizeof(char));
	printf("압축하고자 하는 문자열(대문자) : ");
	scanf("%s", arr);
	root = make_Huffman_tree(arr); // Create the tree
	make_table(root, str, 0, code); // Using tree, make variable length
	i = 0;
	while (arr[i] != NULL) 
	{ 
		strcat(encoding, code[arr[i] - 'A']);
		strcat(encoding, " ");
		i++;
	}
	for (i = 0; i < ind; i++)
		printf("%c : %s\n", node_arr[i].alphabet, code[node_arr[i].alphabet - 'A']);
	printf("압축 결과 : %s\n", encoding); 
	printf("압축 해제 : ");
	decode(encoding, root); 
	return 0;
}