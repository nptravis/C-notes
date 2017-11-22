#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#define ALPHABET 26
#define DICTIONARY "dictionary.txt"

bool load(const char* dictionary);
bool check(const char* word);

typedef struct node
{
	bool is_word;  
	struct node * child[ALPHABET +1];
}node;

node * root;
node * branch;
node * current;

int main(void)
{
	bool loaded = load(DICTIONARY);
	if(!loaded)
	{
		printf("Error, dictionary not loaded\n");
	}
	char* input;
	printf("Type the word you wish to spellcheck: ");
	scanf("%s", input);
	if(check(input))
		{
			printf("Yes, it is in the dictionary :)\n");
		}
	else
		{
			printf("Sorry, that word is not in the dictionary :(\n");
		}



	return 0;
}

// load the dictionary into a trie
bool load(const char* dictionary)
{

	FILE *fp = fopen(dictionary, "r");
  char word[50];
  root = malloc(sizeof(node));
  int j = 0;
  while(j <= 27){
  root->child[j] = NULL;
  j++;
	}

	while(fscanf(fp, "%s", word) != EOF)
	{
	branch = root;
	int len = strlen(word);
	// printf("%s has %i letters\n", word, len);
  for(int i=0; i<len; i++)
  	{
  		int index = (int)(word[i]) - (int)('a');
  		// printf("%c at index %i of %s\n", word[i], i, word);
  		// printf("the index of the child is: %i\n", index); 
  		if((i == 0) && (branch->child[index] == NULL))
  		{
  			branch = malloc(sizeof(node));
  			root->child[index] = branch;
  			branch = root->child[index];
  			// printf("if..\n");
  		}
	  	else if(branch->child[index] == NULL)
	  	{
	  		current = malloc(sizeof(node));
	  		branch->child[index] = current;
	  		branch = current;
	  			// printf("else if..\n");
	  	}
	  	else
	  	{
	  		branch = branch->child[index];	
	  			// printf("else..\n");
	  	}
  	}
  	branch->is_word = true;
		// printf("this is the end of the word's cycle\n");
	}

	fclose(fp);
	return true;
}

bool check(const char* word)
{
	branch = root;

	for(int i = 0; i<strlen(word); i++){

		int index = (int)word[i] - (int)'a';
		if(branch->child[index])
		{
			branch = branch->child[index];
		}
		else
		{
			return false;
		}

	}

	if(branch->is_word)
		{
			return true;
		}
	else
		{
			return false;
		}

	
}

