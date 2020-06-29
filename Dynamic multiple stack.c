#include<stdio.h>
#include<stdlib.h>
#define Max 3

typedef struct
{
	int key;
}ele;

typedef struct stack *stackptr;

typedef struct stack
{
	ele data;
	stackptr link;
}stack;

stackptr top[Max];

void push(int stackno,int item)
{
	stackptr temp = (stackptr)malloc(sizeof(stack));
	temp->data.key=item;
	temp->link=top[stackno];
	top[stackno]=temp;
}

void pop(int stackno)
{
	stackptr del =top[stackno];
	int item;
	item = del->data.key;
	top[stackno]=del->link;
	free(del);
	printf("\n Popped %d from Stack Number %d",item,stackno);
}

void display()
{
	int i;
	stackptr temp;
	for(i=0;i<Max;i++)
	{
		printf("\n Stack Number %d :- \n",i);	
		if(top[i]==NULL)
			printf(" ->Stack Empty !!!\n");
		else
		{
			for(temp=top[i];temp!=NULL;temp=temp->link)
			{
				printf(" %d ",temp->data.key);
			}
		}
	}
}

int main()
{
	int ch=4,i,j;
	ele temp;
	for(i=0;i<Max;i++)
		top[i]=NULL;
	while(1)
	{
		printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n\n Enter Choice :");
		scanf("%d",&ch);
		switch(ch)		
		{
			case 1:
				printf("\n Enter stack number & item : ");
				scanf("%d%d",&j,&temp.key);
				push(j,temp.key);
				break;
			case 2:
				printf("\n Enter stack number : ");
				scanf("%d",&j);
				if(top[j]==NULL)
				{
					printf("\n ERROR : Stack Empty !!!");
				}
				else
				{
					pop(j);
				}
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\n ERROR : WRONG CHOICE !!!\n");
		}
	}
	return 0;
}
