#include<stdio.h>
#include<stdlib.h>
#define Max 3

typedef struct 
{
	int key;
}ele;

typedef struct q *qptr;

typedef struct q
{
	ele data;
	qptr link;
}q;

qptr front[Max],rear[Max];

void enQ(int qno,int item)
{
	qptr temp;
	qptr New = (qptr)malloc(sizeof(q));
	qptr->link=NULL;
	qptr->data.key=item;
	if(front[qno]==NULL)
		front[i]=New;
	else
	{
		for(temp=front[qno];temp->link!=NULL;temp=temp->link);
			temp->link=New;
	}
	rear[qno]=New;			
}		


