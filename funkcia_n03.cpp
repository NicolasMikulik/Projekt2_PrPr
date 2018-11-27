#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
  
// A linked list node 
struct Node 
{ 
    char kategoria[52];
	char znacka[52];
	char predajca[102];
    int cena;
    int vyrobene;
    char stav[202];
    struct Node *next; 
}; 
  
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, FILE *f, int *pocet_zaznamov) 
{ 
	struct Node *current = NULL;
	
	if((f=fopen("auta.txt","r"))==NULL)
	{printf("Zaznamy neboli nacitane.\n");
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
		if(s[strlen(s)]=='\n')s[strlen(s)-1]='\0';
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

void add(struct Node **head_ref, int *pocet_zaznamov) 
{
	int poz,i=1;
	char s[202];
	struct Node* current=(*head_ref);
	
	scanf("%d",&poz);
	if((*pocet_zaznamov)>0 && poz>0)
	{
		if(poz==1)
		{
			struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
			fgets(s,200,stdin);
			fgets(s,200,stdin);
			s[strlen(s)-1]='\0';
			strcpy(new_node->kategoria,s);
			fgets(s,200,stdin);
			s[strlen(s)-1]='\0';
			strcpy(new_node->znacka,s);
			fgets(s,200,stdin);
			s[strlen(s)-1]='\0';
			strcpy(new_node->predajca,s);
			scanf("%d",&new_node->cena);
			scanf("%d",&new_node->vyrobene);
			fgets(s,200,stdin);
			fgets(s,200,stdin);	
			if(s[strlen(s)]=='\n')s[strlen(s)-1]='\0';
			strcpy(new_node->stav,s);
			
			new_node->next=(*head_ref);
			(*head_ref)=new_node;
			(*pocet_zaznamov)++;
			printf("Zaznam pridany na poziciu %d \n",i);
		}
		else
		{
			while(current!=NULL)
			{
				if(poz>(*pocet_zaznamov))
				{
					current = (*head_ref);
					while(current->next!=NULL)
						current=current->next;
					struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
				
				strcpy(new_node->kategoria,"KAMION");
				strcpy(new_node->znacka,"Nissan");
				strcpy(new_node->predajca,"Negatron's landfill");
				new_node->cena=13400;
				new_node->vyrobene=2011;
				strcpy(new_node->stav,"vyrobene zo sopecneho kamena");
				
				new_node->next=current->next;
				current->next=new_node;
				(*pocet_zaznamov)++;
				printf("Zaznam pridany na poziciu %d \n",(*pocet_zaznamov));
				break;
				}
				if((poz-1)==i++)
				{
				struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
				
				strcpy(new_node->kategoria,"KAMION");
				strcpy(new_node->znacka,"Nissan");
				strcpy(new_node->predajca,"Negatron's landfill");
				new_node->cena=13400;
				new_node->vyrobene=2011;
				strcpy(new_node->stav,"vyrobene zo sopecneho kamena");
				
				new_node->next=current->next;
				current->next=new_node;
				
				(*pocet_zaznamov)++;
				printf("Zaznam pridany na poziciu %d \n",i);
				break;
				}
				current=current->next;	
			}
		}
	}
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
  
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int *pocet_zaznamov) 
{ 
   	char subs[55], doms[55];
   	int i;
   	struct Node* prev = *head_ref;
   	struct Node* curr;
   	
	if (*head_ref == NULL) return;
  	scanf("%s",subs);
	strupr(subs);  
	strcpy(doms,(*head_ref)->znacka);
  	strupr(doms);
	if(strstr(doms,subs))
  	{
  		*head_ref=(*head_ref)->next;
  		free(prev);
  		(*pocet_zaznamov)--;
  		//return;
	}
	  prev = (*head_ref);
	  curr = prev->next;
	
	  while (curr != NULL) {
	  	strcpy(doms,curr->znacka);
  		strupr(doms);
	    if(strstr(doms,subs)){
	      prev->next = curr->next;  // Will be NULL at the end of the list.
	      free(curr);
	      curr = prev->next;
	    } else {
	      prev = curr;
	      curr = curr->next;
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
    	printf("kategoria: %s\n", current->kategoria);
    	printf("znacka: %s\n", current->znacka);
    	printf("predajca: %s\n", current->predajca);
        printf("cena: %d\n", current->cena);
		printf("rok_vyroby: %d\n", current->vyrobene);
		printf("stav_vozidla: %s\n", current->stav);  
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
		if(hs[0]=='n') push(&head, f, &pocet_zaznamov);
		if(hs[0]=='p') add(&head, &pocet_zaznamov);  
		if(hs[0]=='v') printList(head);
		if(hs[0]=='h') h(head);
		if(hs[0]=='a') a(&head);
		if(hs[0]=='z') deleteNode(&head, &pocet_zaznamov);
		if(hs[0]=='k') freeAll(head,f,&w);
	}
    
    return 0; 
} 
