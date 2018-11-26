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
void push(struct Node** head_ref, FILE *f, int *pocet_zaznamov) 
{ 
	struct Node *current = NULL;
	
	if((f=fopen("auta.txt","r"))==NULL)
	{printf("Nepodarilo sa otvorit subor.\n");
	exit(0);}
	(*pocet_zaznamov)=0;
    while ((current = (*head_ref)) != NULL)
    {
        (*head_ref) = (*head_ref)->next;
        free(current);
    }
    //(*head_ref) = (struct Node*) malloc(sizeof(struct Node));
    current=(*head_ref);
	char s[51];
	fseek(f,0,SEEK_SET);
	while((fgets(s,50,f))!=NULL)
    {	
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		(*pocet_zaznamov)++;
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
	 	new_node->next=NULL;
        
        
        if((*head_ref)==NULL)
        {
        	//new_node->next = (*head_ref); 
	    	(*head_ref)    = new_node;
	    	current=(*head_ref);
		}
		else
		{
		 	current->next=new_node;
	 		current=current->next;
		}
	 	
	    /*new_node->next = (*head_ref); 
	    (*head_ref)    = new_node;*/
	}
	printf("Nacitalo sa %d zaznamov.\n", (*pocet_zaznamov));
} 

void append(struct Node** head_ref, FILE *f) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	struct Node* current;
	 
    while ((current = (*head_ref)) != NULL)
    {
        (*head_ref) = (*head_ref)->next;
        free(current);
    }
    
    struct Node *last = *head_ref; 

    char s[51];
	fseek(f,0,SEEK_SET);
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
	}
     
    return; 
}
  
int porovnaj(char *s1, char *s2)
{
	int sublen=0,domlen=0,i,j,zhoda=0;
	sublen=strlen(s2);
	domlen=strlen(s1);
	printf("%s %s\n", s1, s2);
	for(i=0;i<domlen;i++)
	{
		zhoda=0;
		for(j=0;j<sublen;j++)
			if(s1[i]==s2[j])zhoda++;
	}
	if(zhoda==sublen)return 1;
}
  
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int *pocet_zaznamov) 
{ 
   	char subs[55], doms[55];
   	int i, wish;
   	struct Node* temp = *head_ref;
   	struct Node* freepop;
   	
	if (*head_ref == NULL) 
    return;
  	scanf("%s %d",subs,&wish);
    if(wish<=(*pocet_zaznamov))
    {
	strupr(subs);  
	strcpy(doms,(*head_ref)->znacka);
  	strupr(doms);
  	printf("%s\n",subs);
	if(strstr(doms,subs) && wish==1)
  	{
  		*head_ref=(*head_ref)->next;
  		free(temp);
  		(*pocet_zaznamov)--;
  		return;
	}
	
  	for(i=1;i<wish-1;i++)
  		temp=temp->next;

  	printf("%s\n",temp->znacka);
  	strcpy(doms,temp->next->znacka);
  	strupr(doms);
  	if(strstr(doms,subs)!=NULL)
  		{
  		freepop=temp->next;
		temp->next=freepop->next;
		free(freepop);
		(*pocet_zaznamov)--;
		}
	}
}

void h(struct Node *node) 
{ 
	struct Node *current=node;
	int i=0, wish;
	char subs[55], doms[55];
	scanf("%s",subs);
    strupr(subs);
	scanf("%d",&wish);
    while (current != NULL) 
    { 
    	strcpy(doms,current->znacka);
  		strupr(doms);
  		printf("%s\n",doms);
  		if(strstr(doms,subs))
  			if(wish>=(current->cena))
		{
    	printf("%d.\n", ++i);
    	printf("%s\n", current->kategoria);
    	printf("%s\n", current->znacka);
    	printf("%s\n", current->predajca);
        printf("%d\n", current->cena);
		printf("%d\n", current->vyrobene);
		printf("%s\n", current->stav);
		}
        current = current->next; 
    }
    printf("\n");
} 

void a(struct Node **node) 
{ 
	struct Node *current=*node;
	int i=0, rok;
	char subs[55], doms[55];
	scanf("%s",subs);
    strupr(subs);
	scanf("%d",&rok);
    while (current != NULL) 
    { 
    	strcpy(doms,current->znacka);
  		strupr(doms);
  		printf("%s\n",doms);
  		if(strstr(doms,subs)!=NULL)
  			if(rok=(current->vyrobene))
				current->cena-=100;
        current = current->next; 
    }
    printf("\n");
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
    int w=1, pocet_zaznamov=0;
    
	while(w==1)
	{
		scanf("%s",hs);
		if(hs[0]=='p') push(&head, f, &pocet_zaznamov); 
		if(hs[0]=='v') printList(head);
		if(hs[0]=='h') h(head);
		if(hs[0]=='a') a(&head);
		if(hs[0]=='z') deleteNode(&head, &pocet_zaznamov);
		if(hs[0]=='k') freeAll(head,f,&w);
	}
    
    return 0; 
} 
