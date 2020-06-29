/* yt concept link : https://www.youtube.com/watch?v=28h-jE6KQVI */

#include<stdio.h>
#define Max 100

char infix[Max],stack[Max];
int top=-1;

void push(char e)
{
	stack[++top]=e;
}

void pop()
{
	printf("%c",stack[top--]);
}

void empty() // prints all remaining characters from stack
{
	while(top!=-1)
	{
		if(stack[top]!='(') // handles invalid brackets expressions
			pop();	
	}
}

int priority(char e) // sets precedence for symbols
{
	if(e=='(') // highest priority
		return 0;
	if(e=='+'||e=='-')
		return 1;
	if(e=='/'||e=='*')
		return 2;
	if(e=='^')
		return 3;
}

void postfix(char infix[])  
{
	int i=0;
	while(infix[i]!='\0') // reads full string
	{
		if(infix[i]=='(') // pushes '(' into the stack
			push(infix[i]);
		else if(infix[i]==')')
		{
			while(stack[top]!='(') // pops all elements from stack until '(' is found
			{
				pop();
			}
			top--;			
		}
		else if(infix[i]=='/'||infix[i]=='*'||infix[i]=='+'||infix[i]=='-'||infix[i]=='^') 
		{
			if(top!=-1)
			{
				while(priority(infix[i])<=priority(stack[top])) 
				{
					pop();
				}
			push(infix[i]);
			}
			else
			{
				push(infix[i]);
			}
		}
		else
		{
			printf("%c",infix[i]);
		}
		i++;
	}
	empty();
}


int main()
{
	printf("\n\n Infix Expression : ");
	scanf("%s",infix);
	printf("\n Postfix Expression : ");
	postfix(infix);
	printf("\n\n");
	return 0;
}





