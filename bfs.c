#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define Max 20

typedef struct graph *gptr;

typedef struct graph
{
	int vdata;
	gptr edge;
}graph;

gptr g[Max];
gptr front,rear;

int visited[Max];
int n;

void createNode(int v1,int v2) // insert func
{
	gptr temp;
	gptr New=(gptr)malloc(sizeof(graph));
	New->vdata=v2;	
	New->edge=NULL;
	if(g[v1]==NULL)
		g[v1]=New;
	else
	{
		for(temp=g[v1];temp->edge!=NULL;temp=temp->edge);
			temp->edge=New;
	}
}

void input() // read_graph func
{
	int noe,i,v1,v2;
	printf("\n Enter Number Of Vertices : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		g[i]=NULL;
	printf("\n Enter Number Of Edges : ");
	scanf("%d",&noe);
	for(i=0;i<noe;i++)
	{
		printf(" Enter Edge (u,v) : ");
		scanf("%d%d",&v1,&v2);
		createNode(v1,v2);		
	}
}

void addq(int v)
{
	gptr temp=(gptr)malloc(sizeof(graph));
	temp->edge=NULL;
	temp->vdata=v;
	if(front==NULL)
		front=temp;
	else
		rear->edge=temp;
	rear=temp;
	
}

int delq()
{
	int v;
	gptr temp;
	temp=front;
	v=temp->vdata;
	temp=temp->edge;
	front=temp;
	//free(temp);
	return v;
}

void bfs(int v)
{
	int i;
	gptr temp;
	for(i=0;i<n;i++)
		visited[i]=FALSE;
	printf("\n %d",v);
	visited[v]=TRUE;
	addq(v);
	while(front)
	{
		v=delq();
		for(temp=g[v];temp;temp=temp->edge)
		{
			if(!visited[temp->vdata])
			{
				printf(" %d",temp->vdata);
				visited[temp->vdata]=TRUE;
				addq(temp->vdata);
			}
		}
	}
}

int main()
{
	front=rear=NULL;
	input();
	printf("\n");
	bfs(0);
	printf("\n");
	return 0;
}















