#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data;
}ele;

ele *q;

int front=0,rear=0,cap=1;

int dQ()
{
	front=(front+1)%cap;
	return q[front].data;
}

void enQ()
{
	int i,n;
	ele *temp;
	if(front==(rear+1)%cap)
	{
		temp = (ele*)malloc(2*cap*sizeof(ele)); // doubles memory 
		if(!temp)
		{
			printf("\n ERROR : No Memory In Heap !!! \n");
			exit(1);
		}
		for(i=0;i<cap;i++)
			temp[i].data=dQ(); // copies existing data of 'q' to 'temp'
		front=2*cap-1; 
		rear=cap-2;
		cap*=2;
		free(q); // frees existing data of q
		q=temp;	// copies existing data of 'temp' to 'q'
	}
	rear=(rear+1)%cap; // calcs rear pos
	printf("\n -> INPUT : Enter element into Queue : ");
	scanf("%d",&q[rear].data);
}

void disp()
{
	int i;
	if(front==rear)
	{
		printf("\n ERROR : Queue Empty !!! \n");
		exit(1);
	}	
	printf("\n => OUTPUT : ");
	for(i=(front+1)%cap;i!=(rear+1)%cap;i=(i+1)%cap)	
	{
		printf(" %d ",q[i].data);
	}	
	printf("\n  > STATUS |Front %d|Rear %d|Capacity %d| \n",front,rear,cap);
}

int main()
{
	int c=4;
	q=(ele*)malloc(sizeof(ele));
	while(1)
	{
		printf("\n 1.Add\n 2.Delete\n 3.Display\n 4.Exit\n\n Enter Choice :");
		scanf("%d",&c);
		switch(c)		
		{
			case 1:
				enQ();
				break;
			case 2:
				dQ();
				break;
			case 3:
				disp();
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
