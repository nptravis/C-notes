#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// global variable definitions
int const HASH_MAX = 50;

// node structure
typedef struct node
{
	char word[50];
	struct node * next;
}node;

//hash function
unsigned int hash(char *str)
{
	int sum = 0;
	for( int j = 0; str[j] != '\0'; j++)
{
	sum += str[j];
}
return sum % HASH_MAX;
}

node * hashtable[50];

int main(void)
{
	FILE *fp = fopen("dictionary.txt", "r");

	if (fp == NULL)
	{
		printf("Error, can't find/read file\n");
		return 1;
	}

	node * temp;
	node * head;
	node * p;
	char word1[50];

	while(fscanf(fp, "%s", word1) != EOF){
		
		// create new node
		temp = malloc(sizeof(node));

		// error check
		if(temp == NULL)
		{
			fclose(fp);
			printf("Error, unable to malloc new node\n");
			return 2;
		}

		// copy word into the node, set it's pointer to null
		strcpy(temp->word, word1);
		temp->next = NULL;

		// hash word
		int hWord = hash(word1);

		// insert word into hashtable according to it's hash code
		if(hashtable[hWord] == NULL)
		{
			hashtable[hWord] = temp;
			// printf("first word in index location %i, is %s\n", hWord, hashtable[hWord]->word);
		} 
		else
		{
			temp->next = hashtable[hWord]->next;
			hashtable[hWord]->next = temp;
		}
	}

// displaying members of index locations words linked together
 for(int i = 0; i < HASH_MAX; i++)
 	{
 		p = hashtable[i];
 		printf("Words at location %i are: \n", i);
 		while(p != NULL)
			{
				printf("%s, ", p->word);
				p = p->next;
			}
			printf("\n");
 	}
	fclose(fp);
	return 0;
}





		
	

