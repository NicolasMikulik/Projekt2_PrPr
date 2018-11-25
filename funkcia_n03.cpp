#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
  
// A linked list node 
struct Node 
{ 
    char kategoria[51];
	char znacka[51];
	char predajca[51];
    int cena;
    int vyrobene;
    char stav[51];
    struct Node *next; 
}; 
  
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, FILE *f) 
{ 
	char s[51];

	while((fgets(s,50,f))!=NULL)
    {	
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(new_node->kategoria,s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(new_node->znacka,s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(new_node->predajca,s);
		fgets(s,50,f);
		new_node->cena=atoi(s);
		fgets(s,50,f);
		new_node->vyrobene=atoi(s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(new_node->stav,s);
		printf("%s\n",new_node->znacka);
	 
	    new_node->next = (*head_ref); 
	    (*head_ref)    = new_node;
	}
} 

/*void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));  
    struct Node *last = *head_ref; 

    new_node->data  = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
    while (last->next != NULL) 
        last = last->next; 

    last->next = new_node; 
    return; 
} */
  
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position) 
{ 
   if (*head_ref == NULL) 
      return; 

   struct Node* temp = *head_ref; 
  
    if (position == 0) 
    { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    if (temp == NULL || temp->next == NULL) 
         return; 

    struct Node *next = temp->next->next;  
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
} 
  
// This function prints contents of linked list starting from 
// the given node 
void printList(struct Node *node) 
{ 
	struct Node *current=node;
	int i=0;
    while (current != NULL) 
    { 
    	printf("%d.\n", ++i);
    	printf("%s\n", current->kategoria);
    	printf("%s\n", current->znacka);
    	printf("%s\n", current->predajca);
        printf("%d\n", current->cena);
		printf("%d\n", current->vyrobene);
		printf("%s\n", current->stav);  
        current = current->next; 
    }
    printf("\n");
} 

void freeAll(struct Node *head, FILE *f, int *w)
{
    struct Node *current = NULL;

    while ((current = head) != NULL)
    {
        head = head->next;
        free(current);
    }
    if(f!=NULL)
    fclose(f);
    *w=0;
}
 
/* Drier program to test above functions*/
int main() 
{ 
    struct Node* head = NULL, *new_node=NULL; 
    FILE *f=NULL;
    char hs[51];
    int w=1;
    
  	if((f=fopen("auta.txt","r"))==NULL)
	{printf("Nepodarilo sa otvorit subor.\n");
	exit(0);}
	
	while(w==1)
	{
		scanf("%s",hs);
		if(hs[0]=='p')
		{
		push(&head, f); 
	    puts("\nCreated Linked List: "); 
	    printList(head); 
	    deleteNode(&head, 1); 
	    puts("\nLinked List after Deletion at position 1: "); 
	    printList(head);
		}
		
		if(hs[0]=='k')
		{
		freeAll(head,f,&w);
		}
	}
    
    return 0; 
} 
