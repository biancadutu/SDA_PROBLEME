#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct lista
{
	int buc;
	struct lista* pNext;
}NODE, *pNODE, **ppNODE;

void addNode(ppNODE,pNODE);
void listTraversal(pNODE);

int main()
{
	pNODE prim = NULL, p = NULL, tmp = NULL, prim1 = NULL, tmp1 = NULL;
	int i,n,k;
	
	scanf("%i", &n);
	if(n<=0 || n>20)
	{
		printf("Numar incorect");
		exit (EXIT_FAILURE);
	}
    
    addNode(&prim,p);
    
    p = prim;
    for(i=1;i<n;i++)
    {
    	addNode(&prim,p);
    	p = p->pNext;
	}
	

    p = NULL;
    addNode(&prim1,p);
     p = prim1;
    for(i=1;i<n;i++)
    {
    	addNode(&prim,p);
    	p = p->pNext;
	}
//	listTraversal(prim);
//    listTraversal(prim1);

     tmp = prim;
     tmp1 = prim1;
     
     while(tmp!=NULL && tmp1!=NULL)
     {
     	if(tmp->buc >= tmp1->buc)
     	{
     	   k = 0;
		}
		else 
		k = 1;
		 
		tmp = tmp->pNext;
     	tmp1 = tmp1->pNext;
	 }
	 
	 if(k==0)
	 printf("Comanda acceptata\n");
	 else 
	 printf("Comanda respinsa\n");
} 
 
void addNode(ppNODE ppPrim, pNODE p)
{
	pNODE q = NULL;
	q = (pNODE)malloc(sizeof(NODE));
	assert(q!=NULL);
	scanf("%i", &q->buc);
	
	if(p == NULL)
	{
		q->pNext = *ppPrim;
		*ppPrim = q;
	}
	
	else
	{
		q->pNext = p->pNext;
		p->pNext = q;
	}
	
	return;
	
}

void listTraversal(pNODE pPrim)
{
	pNODE tmp = pPrim;
	
	while(tmp!=NULL)
	{
		printf("%i ", tmp->buc);
		tmp = tmp->pNext;
	}
}
