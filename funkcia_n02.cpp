#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char kategoria[51];
	char znacka[51];
	char predajca[51];
    int cena;
    int vyrobene;
    char stav[51];
    struct node * next;
} node_t;

/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(node_t **head_ref, int position) 
{ 
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   node_t* temp = *head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of ndoes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    node_t *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
} 

int addNodeBottom(int val, node_t *head)
{    
    node_t *current = head;
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    if (newNode == NULL) {
        printf("malloc failed\n");
        exit(-1);
    }    
	strcpy(newNode->kategoria,"spectacle");
    strcpy(newNode->znacka,"melee");
	strcpy(newNode->predajca,"visual");
	newNode->cena = 100;
    newNode->vyrobene = 220;
    strcpy(newNode->stav,"epic");
    
    printf("%s %d\n",newNode->kategoria, newNode->cena);
	newNode->next = NULL;

    while (current->next->next) {
        current = current->next;
    }    
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

void vypis(node_t *head)
{
	node_t *begin = head;
	int i=0;
	while(begin->next)
	{
		printf("%d.",++i);
		printf("%s\n",begin->kategoria);
		printf("%s\n",begin->znacka);
		printf("%s\n",begin->predajca);
		printf("%d\n",begin->cena);
		printf("%d\n",begin->vyrobene);
		printf("%s\n",begin->stav);
		begin=begin->next;
	}
}

int main()
{
	node_t * head=NULL, *begin=NULL, *insert=NULL;
	int i=0, w=0;
	char s[40],c;
	FILE *f=NULL;
	
	if((f=fopen("auta.txt","r"))==NULL)
	{printf("Nepodarilo sa otvorit subor.\n");
	exit(0);}
	head=(node_t*)malloc(sizeof(node_t));
	while(w!=3)
	{
	begin=head;
	fseek(f,0,SEEK_SET);
	while((fgets(s,50,f))!=NULL)
	{
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(begin->kategoria,s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(begin->znacka,s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(begin->predajca,s);
		fgets(s,50,f);
		begin->cena=atoi(s);
		fgets(s,50,f);
		begin->vyrobene=atoi(s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(begin->stav,s);
		printf("%s\n",begin->znacka);
		begin->next=(node_t*)malloc(sizeof(node_t));
		begin=begin->next;
	}
	begin->next=NULL;

	addNodeBottom(10,head);
	/*begin=head;
	while(begin->next)
		begin=begin->next;
		
	insert=(node_t*)malloc(sizeof(node_t));
	if(insert==NULL)printf("Nepodarilo sa alokovat pamat.\n");
	scanf("%s",insert->kategoria);
	printf("%s\n",insert->kategoria);
	scanf("%s",insert->znacka);
	printf("%s\n",insert->znacka);
	scanf("%s",insert->predajca);
	scanf("%d",&insert->cena);
	scanf("%d",&insert->vyrobene);
	scanf("%s",insert->stav);
	insert->next=NULL;
	//insert->next=begin->next;
	begin->next=insert;*/
	deleteNode(&head,1);
	vypis(head);
	/*begin=head;
	i=0;
	while(begin->next)
	{
		printf("%d.",++i);
		printf("%s\n",begin->kategoria);
		printf("%s\n",begin->znacka);
		printf("%s\n",begin->predajca);
		printf("%d\n",begin->cena);
		printf("%d\n",begin->vyrobene);
		printf("%s\n",begin->stav);
		begin=begin->next;
	}*/

	w++;
	}
	while((begin=head)!=NULL)
	{
		head=head->next;
		free(begin);
	}
	free(insert);
	fclose(f);
	
	return 0;
}
