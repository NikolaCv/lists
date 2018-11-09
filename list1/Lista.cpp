#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int cmp(char *s1, char *s2)
{
	int n ;
	if( strlen(s1) > strlen(s2) )
	n = strlen(s1) ;
	else
	n = strlen(s2) ;
	for( int i = 0 ; i < n ; ++i)
	if(s1[i]!=s2[i]) return 0;
	return 1;
}

typedef struct LCVOR
{
	char name[30] ;
	struct LCVOR *sl ;
}LCVOR;

void start(LCVOR **l)
{
	LCVOR *novi = (LCVOR*)malloc(sizeof(LCVOR)) ;
	gets( novi->name ) ;
	novi->sl = *l ;
	*l = novi ;
}

void end(LCVOR **l)
{
	LCVOR *novi = (LCVOR*)malloc(sizeof(LCVOR)) ;
	gets( novi->name );
	LCVOR *t = *l ;
	if(*l == NULL)
	{
		novi->sl = *l ;
		*l = novi ;
	}
	else
	{
		while( t->sl )
		t = t->sl ;
		t->sl = novi ;
		novi->sl = NULL ;
	}
}

void obrisi(LCVOR **l)
{
	LCVOR *t = *l, *t1 = *l ;
	char ch[30] ;
	gets(ch);
	
	if( cmp( ch , t->name ) )
	{
		t = t->sl ;
		free(*l);
		*l = t ;
	}
	else
	{
		t = t->sl ;
		while(t)
		{
			if( cmp( ch , t->name ) )
			{
				LCVOR *p = t ;
				t1->sl = t->sl ;
				t = t->sl ;
				free(p);
			}
			else
			{
				t1 = t ;
				t = t->sl ;
			}
		}
	}
	printf("Obrisano.\n");
}

void provera(LCVOR *l)
{
	char ch[30] ;
	gets(ch);
	bool t = true ;
	while( l )
	{
		if( cmp( ch , l->name ) )
		{
			printf("Ime je na listi.\n") ;
			t = false ;
			break ;
		}
		l = l->sl ;
	}
	if(t)
	printf("Ime nije na listi.\n") ;
}

void izbrisi(LCVOR *l)
{
	LCVOR *t = l->sl ;
	while( l->sl )
	{
		if(cmp( l->name , t->name ) )
		{
			LCVOR *p = t ;
			t = t->sl ;
			l->sl = t ;
			free(p) ;
		}
		else
		{
			t = t->sl ;
			l = l->sl ;
		}
	}
}

void ispis(LCVOR *l)
{
	if(l)
	{
		cout << l->name << "\t"  ;
		ispis( l->sl );
	}
}

int duzina(LCVOR *l)
{
	int i = 1 ;
	LCVOR *t = l;
	while( t->sl )
	{
		t = t->sl ;
		++i;
	}
	return i;
}

void menu(int *opt)
{
	printf("1. Dodavanje na pocetak liste\n");
	printf("2. Dodavanje na kraj liste\n");
	printf("3. Obrisi ime\n");
	printf("4. Provera da li je ime na listi\n");
	printf("5. Brisanje svih nizova istih imena\n");
	printf("6. Ispis liste\n");
	printf("7. Duzina liste\n");
	printf("0. Kraj\n");
	scanf("%d",opt);
	fflush(stdin);
}

int main()
{
	LCVOR *l = NULL ;
	int opt = 1 ;
	
	while(opt)
	{
		system("CLS");
		menu( &opt );
		switch( opt )
		{
			case 1:
			{
				start(&l);	printf("Dodato na pocetak.\n");		system("PAUSE");
				break;
			}
			case 2:
			{
				end(&l);	printf("Dodato na kraj.\n");		system("PAUSE");
				break;
			}
			case 3:
			{
				obrisi(&l);	system("PAUSE");
				break;
			}
			case 4:
			{
				provera(l);	system("PAUSE");		
				break;
			}
			case 5:
			{
				izbrisi(l);	printf("Izbrisani svi nizovi imena.\n");	system("PAUSE");
			}
			case 6:
			{
				ispis(l);	system("PAUSE");
				break;
			}
			case 7:
			{
				printf("Duzina liste je: %d", duzina(l));			system("PAUSE");
			}
		}
	}
	system("PAUSE");
}
