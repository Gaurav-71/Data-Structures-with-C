#include<stdio.h>
#include<stdlib.h>

#define Max 20
#define TRUE 1
#define FALSE 0

typedef struct graph *gptr;

typedef struct graph
{
	int vdata;
	gptr edge;
}graph;

gptr g[Max];

int nv;
int visited[Max];

void createNode(int v1,int v2)
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

void readGraph()
{
	int i,v1,v2,noe;
	printf("\n Enter No. of Vertices : ");
	scanf("%d",&nv);
	for(i=0;i<nv;i++)
		g[i]=NULL;
	printf("\n Enter No. of Edges : ");
	scanf("%d",&noe);
	for(i=0;i<noe;i++)
	{
		printf(" Enter Edge (u,v) : ");
		scanf("%d%d",&v1,&v2);
		createNode(v1,v2);
	}
}

void dfs(int v)
{
	gptr temp;
	printf(" %d ",v);
	visited[v]=TRUE;
	for(temp=g[v];temp;temp=temp->edge)
	{
		if(!visited[temp->vdata])
			dfs(temp->vdata);
	}
}

int main()
{
	int i;
	readGraph();
	for(i=0;i<nv;i++)
		visited[i]=FALSE;
	dfs(0);
	printf("\n\n");
	return 0;
}
