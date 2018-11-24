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

int main()
{
	node_t * head=NULL, *begin=NULL;
	int i;
	char s[40];
	FILE *f=NULL;
	
	if((f=fopen("auta.txt","r"))==NULL)
	{printf("Nepodarilo sa otvorit subor.\n");
	exit(0);}
	
	head=(node_t*)malloc(sizeof(node_t));
	begin=head;
	
	while((fgets(s,50,f))!=NULL)
	{
		fgets(s,50,f);
		strcpy(begin->kategoria,s);
		fgets(s,50,f);
		strcpy(begin->znacka,s);
		fgets(s,50,f);
		strcpy(begin->predajca,s);
		fgets(s,50,f);
		begin->cena=atoi(s);
		fgets(s,50,f);
		begin->vyrobene=atoi(s);
		fgets(s,50,f);
		strcpy(begin->stav,s);
		printf("%s",begin->znacka);
		begin->next=(node_t*)malloc(sizeof(node_t));
		begin=begin->next;
	}
	
	begin->next=NULL;
	while((begin=head)!=NULL)
	{
		head=head->next;
		free(begin);
	}
	//free(head);
	
	fclose(f);
	
	return 0;
}
