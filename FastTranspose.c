#include <stdio.h>
#define MAX_TERMS 101 
#define MAX_COL 100

typedef struct
{
     int row;
     int col;
     int value;
}trp;

trp a[MAX_TERMS],b[MAX_TERMS];

void status(char str[],int n)
{
	printf("\n STATUS --- %s | %d --- STATUS\n",str,n);
}

void transpose(trp a[],trp b[])
{
     int rt[MAX_COL],sp[MAX_COL];
     int i,j,nc=a[0].col,nt=a[0].value;
     b[0].row=nc;
     b[0].col=a[0].row;
     b[0].value=nt;
	status("nc",nc);
	status("nt",nt);
	status("b[0].row",b[0].row);
	status("b[0].col",b[0].col);
	status("b[0].value",b[0].value);
     if(nt>0)
     {
            for(i=0;i<nc;i++)
		{
                rt[i]=0;
		status("rt[i]=0",rt[i]);
		}
            for(i=1;i<=nt;i++)
		{
                rt[a[i].col]++;
		status("rt[a[i].col]++",rt[a[i].col]);
		}
            sp[0]=1;
		status("sp[0]=1",sp[0]);
            for(i=1;i<nc;i++)
		{
                sp[i]=sp[i-1]+rt[i-1];
		status("sp[i]=sp[i-1]+rt[i-1]",sp[i]);
		}
            for(i=1;i<=nt;i++)
            {   
		j=sp[a[i].col]++;
		//status("SWAP : j=sp[a[i].col]++",j);
                b[j].row=a[i].col;
		//status("SWAP : b[j].row=a[i].col",b[j].row);
                b[j].col=a[i].row;
		//status("SWAP : b[j].col=a[i].row",b[j].col);
                b[j].value=a[i].value;
		//status("SWAP : b[j].value=a[i].value",b[j].value);
            }
     }
}

int main()
{   
    printf("Enter max rows,cols and entries\n");
    scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].value);
    int i;
    printf("Enter entries\n");
    for(i=1;i<=a[0].value;i++)
    {
             scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }
    transpose(a,b);
    printf("Transposed matrix is \n");
    for(i=1;i<=a[0].value;i++)
    {
         printf("%d    %d   %d \n",b[i].row,b[i].col,b[i].value);
    }
   return 0;   
}

