#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node
{
	int a, b;
	struct Node *sl;
}node;


class farey
{
	node *pbg;
	int n;
	public:
		farey();
		void next();
		farey nthfarey(int c);
		void print();

};

farey::farey()
{
	pbg=NULL;
	node *novi=(node*)malloc(sizeof(node));
	node *novi1=(node*)malloc(sizeof(node));
	novi->a=0;
	novi->b=1;
	novi1->a=1;
	novi1->b=1;
	novi1->sl=NULL;
	novi->sl=novi1;
	pbg=novi;
	n=1;
}

void farey::next()
{
	node *p=pbg;
	while(p->sl)
	{
		if(p->b+p->sl->b < n + 2 ) 
		{
			node *novi=(node*)malloc(sizeof(node));
			novi->a=p->a+p->sl->a;
			novi->b=p->b+p->sl->b;
			novi->sl=p->sl;
			p->sl=novi;
			p=p->sl->sl;
		}
		else
		p=p->sl;
	}
	n++;
}

farey farey::nthfarey(int c)
{
	farey nth;
	while(nth.pbg->sl->b<c)
	nth.next();
	return nth;
}

void farey::print()
{
	node *p=pbg;
	cout<<" | ";
	while(p)
	{
		cout<<p->a<<"/"<<p->b<<" | ";
		p=p->sl;
	}
}

int main()
{
	farey nth;
	int n;
	cout<<"Level of Farey's sequence: ";
	cin>>n;
	nth=nth.nthfarey(n);
	nth.print();
}
