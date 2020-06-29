#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 10

char symbols[]={'+','-','*','/','%','^'};
int stack[Max];
int top=-1;
char postfix[Max];

void push(int e)
{
	stack[++top]=e;
}

int pop()
{
	return stack[top--];
}

char search(char c) // does a linear search to check operator
{
	int i;
	for(i=0;i<6;i++)
	{
		if(c==symbols[i])
		{
			return c;		
		}
	}
	return -1; // returns -1 if its a number
}

void eval(char arr[])
{
	char ch;
	int op1=1,op2=1,i=0;
	while(arr[i]!='\0')
	{
		ch=search(arr[i]);
		if(ch==-1)
			push(arr[i]-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':
					push(op1+op2);
					break;
				case '-':
					push(op1-op2);
					break;				
				case '*':
					push(op1*op2);
					break;
				case '/':
					if(op2==0)	
					{			
						printf("\n ERROR : Divide by zero error !!!");				
						exit(1);
					}
					else				
						push(op1/op2);
					break;
				case '^':
					push(pow(op1,op2));
					break;
			}
		}
		i++;
	}
}

int main()
{
	printf("\n\n Enter Expression : ");
	scanf("%s",postfix);
	eval(postfix);
	printf("\n Solution : %d \n\n",stack[top]);	
	return 0;
}



