#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

// structure for creating nodes
// typedef struct node
// {
// 	char * word;
// 	struct node * next;
// }node;

// open the dictionary file
// FILE *fp = fopen(dictionary, "r");


// node * createLinkedList(char scanWord); // will return the address of the first node

// void displayList(node * head);

int main(void)
{

FILE *fp = fopen("dictionary.txt", "r");
// char * tempWord;
// node * head = NULL;
// node * temp = NULL;
// node * p = NULL;
char word = fscanf(fp, "%s", word);
printf("%s\n", word);
// while (fscanf(fp, "%s", tempWord) != EOF)
// 		{
// 			// temp = (node*)malloc(sizeof(node));
// 			// temp->word = tempWord;
// 			// temp->next = NULL;

// 			// if(head == NULL)
// 			// {
// 			// 	head = temp;
// 			// }
// 			// else
// 			// {
// 			// 	p = head;
// 			// 	while(p->next != NULL)
// 			// 	{
// 			// 		p = p->next;
// 			// 	}
// 			// 	p->next = temp;
// 			// }
// 			printf("%s\n", tempWord);

// 		}
fclose(fp);
return 0;

}





		
	

