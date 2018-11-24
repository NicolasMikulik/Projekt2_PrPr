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
	node_t * head=NULL, *begin=NULL, *insert=NULL;
	int i=0;
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
	begin=head->next;
	
	insert=(node_t*)malloc(sizeof(node_t));
	insert->next=NULL;
	scanf("%s",insert->kategoria);
	scanf("%s",insert->znacka);
	scanf("%s",insert->predajca);
	scanf("%d",&insert->cena);
	scanf("%d",&insert->vyrobene);
	scanf("%s",insert->stav);
	
	insert->next=begin->next;
	begin->next=insert;
	begin=begin->next;
	begin=begin->next;
	printf("%s\n",head->znacka);
	printf("%s\n",begin->znacka);
	
	begin=head;
	while(begin->next!=NULL)
	{
		printf("%d.",++i);
		printf("%s",begin->kategoria);
		printf("%s",begin->znacka);
		printf("%s",begin->predajca);
		printf("%d\n",begin->cena);
		printf("%d\n",begin->vyrobene);
		printf("%s",begin->stav);
		begin=begin->next;
	}
	
	begin=head;
	while(begin->next!=NULL)
		begin=begin->next;
	insert=begin->next;
	insert=(node_t*)malloc(sizeof(node_t));
	insert->next=NULL;
	scanf("%s",insert->kategoria);
	scanf("%s",insert->znacka);
	scanf("%s",insert->predajca);
	scanf("%d",&insert->cena);
	scanf("%d",&insert->vyrobene);
	scanf("%s",insert->stav);
	
	begin=head->next;
	insert->next=begin->next;
	begin->next=insert;

	begin=head;
	while(begin->next!=NULL)
	{
		printf("%d.",++i);
		printf("%s",begin->kategoria);
		printf("%s",begin->znacka);
		printf("%s",begin->predajca);
		printf("%d\n",begin->cena);
		printf("%d\n",begin->vyrobene);
		printf("%s",begin->stav);
		begin=begin->next;
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
