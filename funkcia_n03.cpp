#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
  
struct zaznam 
{ 
    char kategoria[52];
	char znacka[52];
	char predajca[102];
    int cena;
    int vyrobene;
    char stav[202];
    struct zaznam *next; 
}; 
  
void push(struct zaznam	**zaciatok, FILE *f, int *pocet_zaznamov) 
{ 
	struct zaznam *aktualny=NULL;
	
	if((f=fopen("auta.txt","r"))==NULL)
	{printf("Zaznamy neboli nacitane.\n");
	exit(0);}
	(*pocet_zaznamov)=0;
    while ((aktualny=(*zaciatok)) != NULL)
    {
        (*zaciatok)=(*zaciatok)->next;
        free(aktualny);
    }
    aktualny=(*zaciatok);
	char s[51];
	fseek(f,0,SEEK_SET);
	while((fgets(s,50,f))!=NULL)
    {	
		struct zaznam* novy_zaznam = (struct zaznam*) malloc(sizeof(struct zaznam));
		(*pocet_zaznamov)++;
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(novy_zaznam->kategoria,s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(novy_zaznam->znacka,s);
		fgets(s,50,f);
		s[strlen(s)-1]='\0';
		strcpy(novy_zaznam->predajca,s);
		fgets(s,50,f);
		novy_zaznam->cena=atoi(s);
		fgets(s,50,f);
		novy_zaznam->vyrobene=atoi(s);
		fgets(s,50,f);
		if(s[strlen(s)]=='\n')s[strlen(s)-1]='\0';
		strcpy(novy_zaznam->stav,s);
	 	novy_zaznam->next=NULL;
        
        if((*zaciatok)==NULL)
        {
	    	(*zaciatok)=novy_zaznam;
	    	aktualny=(*zaciatok);
		}
		else
		{
		 	aktualny->next=novy_zaznam;
	 		aktualny=aktualny->next;
		}
	}
	printf("Nacitalo sa %d zaznamov.\n", (*pocet_zaznamov));
} 

void add(struct zaznam **zaciatok, int *pocet_zaznamov) 
{
	int poz,i=1;
	char s[202];
	struct zaznam* aktualny=(*zaciatok);
	
	scanf("%d",&poz);
	if((*pocet_zaznamov)>0 && poz>0)
	{
		if(poz==1)
		{
			struct zaznam* novy_zaznam = (struct zaznam*) malloc(sizeof(struct zaznam)); 
			fgets(s,200,stdin);
			fgets(s,200,stdin);
			s[strlen(s)-1]='\0';
			strcpy(novy_zaznam->kategoria,s);
			fgets(s,200,stdin);
			s[strlen(s)-1]='\0';
			strcpy(novy_zaznam->znacka,s);
			fgets(s,200,stdin);
			s[strlen(s)-1]='\0';
			strcpy(novy_zaznam->predajca,s);
			scanf("%d",&novy_zaznam->cena);
			scanf("%d",&novy_zaznam->vyrobene);
			fgets(s,200,stdin);
			fgets(s,200,stdin);	
			if(s[strlen(s)]=='\n')s[strlen(s)-1]='\0';
			strcpy(novy_zaznam->stav,s);
			
			novy_zaznam->next=(*zaciatok);
			(*zaciatok)=novy_zaznam;
			(*pocet_zaznamov)++;
			//printf("Zaznam pridany na poziciu %d \n",i);
		}
		else
		{
			while(aktualny!=NULL)
			{
				if(poz>(*pocet_zaznamov))
				{
					aktualny = (*zaciatok);
					while(aktualny->next!=NULL)
						aktualny=aktualny->next;
					struct zaznam* novy_zaznam = (struct zaznam*) malloc(sizeof(struct zaznam)); 
				
					fgets(s,200,stdin);
					fgets(s,200,stdin);
					s[strlen(s)-1]='\0';
					strcpy(novy_zaznam->kategoria,s);
					fgets(s,200,stdin);
					s[strlen(s)-1]='\0';
					strcpy(novy_zaznam->znacka,s);
					fgets(s,200,stdin);
					s[strlen(s)-1]='\0';
					strcpy(novy_zaznam->predajca,s);
					scanf("%d",&novy_zaznam->cena);
					scanf("%d",&novy_zaznam->vyrobene);
					fgets(s,200,stdin);
					fgets(s,200,stdin);	
					if(s[strlen(s)]=='\n')s[strlen(s)-1]='\0';
					strcpy(novy_zaznam->stav,s);
				
				novy_zaznam->next=aktualny->next;
				aktualny->next=novy_zaznam;
				(*pocet_zaznamov)++;
				//printf("Zaznam pridany na poziciu %d \n",(*pocet_zaznamov));
				break;
				}
				if((poz-1)==i++)
				{
				struct zaznam* novy_zaznam = (struct zaznam*) malloc(sizeof(struct zaznam)); 
				
				fgets(s,200,stdin);
				fgets(s,200,stdin);
				s[strlen(s)-1]='\0';
				strcpy(novy_zaznam->kategoria,s);
				fgets(s,200,stdin);
				s[strlen(s)-1]='\0';
				strcpy(novy_zaznam->znacka,s);
				fgets(s,200,stdin);
				s[strlen(s)-1]='\0';
				strcpy(novy_zaznam->predajca,s);
				scanf("%d",&novy_zaznam->cena);
				scanf("%d",&novy_zaznam->vyrobene);
				fgets(s,200,stdin);
				fgets(s,200,stdin);	
				if(s[strlen(s)]=='\n')s[strlen(s)-1]='\0';
				strcpy(novy_zaznam->stav,s);
				
				novy_zaznam->next=aktualny->next;
				aktualny->next=novy_zaznam;
				
				(*pocet_zaznamov)++;
				//printf("Zaznam pridany na poziciu %d \n",i);
				break;
				}
				aktualny=aktualny->next;	
			}
		}
	}
}
  
void vymaz_zaznam(struct zaznam **zaciatok, int *pocet_zaznamov) 
{ 
   	char podstring[102], hlavny[102];
   	int vymazane=0;
   	struct zaznam* pred = *zaciatok;
   	struct zaznam* aktualny;
   	
	if (*zaciatok == NULL) return;
  	scanf("%s",podstring);
	strupr(podstring);  

	while(strstr(strupr(strcpy(hlavny,(*zaciatok)->znacka)),podstring)!=NULL)
  	{
  		*zaciatok=(*zaciatok)->next;
  		free(pred);
  		(*pocet_zaznamov)--;
  		vymazane++;
	}
	
	  pred=(*zaciatok);
	  aktualny=pred->next;
	
	  while (aktualny != NULL) {
	  	strcpy(hlavny,aktualny->znacka);
  		strupr(hlavny);
	    if(strstr(hlavny,podstring))
		{
	      pred->next=aktualny->next;  // Will be NULL at the end of the list.
	      free(aktualny);
	      aktualny=pred->next;
	      (*pocet_zaznamov)--;
	      vymazane++;
	    } 
		else 
		{
	      pred=aktualny;
	      aktualny=aktualny->next;
	    }
	  }
	  printf("Vymazalo sa %d zaznamov.\n", vymazane);
}

void h(struct zaznam *zaznam) 
{ 
	struct zaznam *aktualny=zaznam;
	int i=0, wish, check=0;
	char podstring[102], hlavny[102];
	scanf("%s",podstring);
    strupr(podstring);
	scanf("%d",&wish);
    while (aktualny != NULL) 
    { 
    	strcpy(hlavny,aktualny->znacka);
  		strupr(hlavny);
  		if(strstr(hlavny,podstring))
  			if(wish>=(aktualny->cena))
			{
		    	printf("%d.\n", ++i);
		    	printf("kategoria: %s\n", aktualny->kategoria);
		    	printf("znacka: %s\n", aktualny->znacka);
		    	printf("predajca: %s\n", aktualny->predajca);
		        printf("cena: %d\n", aktualny->cena);
				printf("rok_vyroby: %d\n", aktualny->vyrobene);
				printf("stav_vozidla: %s\n", aktualny->stav);  
				check=1;
			}
        aktualny = aktualny->next; 
    }
    if(check==0)printf("V ponuke nie su pozadovane auta\n");
} 

void a(struct zaznam **zaznam) 
{ 
	struct zaznam *aktualny=(*zaznam);
	int i=0, rok, upravene=0;
	char podstring[102], hlavny[102];
	
	scanf("%s",podstring);
    strupr(podstring);
	scanf("%d",&rok);
	
    while (aktualny != NULL) 
    { 
    	strcpy(hlavny,aktualny->znacka);
  		strupr(hlavny);
  		printf("%s\n",hlavny);
  		if(strstr(hlavny,podstring)!=NULL)
  		{
  			if(rok==(aktualny->vyrobene))
  			{
				aktualny->cena-=100;  		
				upravene++;
				if(aktualny->cena<=0) aktualny->cena=0;		
			}
		}
        aktualny = aktualny->next; 
    }
    printf("Aktualizovalo sa %d zaznamov,\n", upravene);
} 

void printList(struct zaznam *zaciatok) 
{ 
	struct zaznam *aktualny=zaciatok;
	int i=0;
    while (aktualny != NULL) 
    { 
    	printf("%d.\n", ++i);
    	printf("kategoria: %s\n", aktualny->kategoria);
    	printf("znacka: %s\n", aktualny->znacka);
    	printf("predajca: %s\n", aktualny->predajca);
        printf("cena: %d\n", aktualny->cena);
		printf("rok_vyroby: %d\n", aktualny->vyrobene);
		printf("stav_vozidla: %s\n", aktualny->stav);  
        aktualny = aktualny->next; 
    }
    printf("\n");
} 

void ukonci(struct zaznam *zaciatok, FILE *f, int *w)
{
    struct zaznam *aktualny = NULL;

    while ((aktualny = zaciatok) != NULL)
    {
        zaciatok = zaciatok->next;
        free(aktualny);
    }
    if(f!=NULL)
    fclose(f);
    *w=0;
}
 
int main() 
{ 
    struct zaznam* zaciatok = NULL, *novy_zaznam=NULL; 
    FILE *f=NULL;
    char hs[5];
    int w=1, pocet_zaznamov=0;
    
	while(w==1)
	{
		scanf("%s",hs);
		if(hs[0]=='n') push(&zaciatok, f, &pocet_zaznamov);
		if(hs[0]=='p') add(&zaciatok, &pocet_zaznamov);  
		if(hs[0]=='v') printList(zaciatok);
		if(hs[0]=='h') h(zaciatok);
		if(hs[0]=='a') a(&zaciatok);
		if(hs[0]=='z') vymaz_zaznam(&zaciatok, &pocet_zaznamov);
		if(hs[0]=='k') ukonci(zaciatok,f,&w);
	}
    
    return 0; 
} 
