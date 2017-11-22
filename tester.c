#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct node
{
	bool is_word;  
	struct node * child[27];
}node;

node * root;
node * branch;
node * current;

int main(void)
{	
	root = malloc(sizeof(node));
  root->child[1] = branch;
	if(root->child[1] == NULL)
	{
		printf("ok...\n");
	}
	
	return 0;
}
