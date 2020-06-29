#include <stdio.h>
#include <stdlib.h>

int found = 0;

struct node{
	int data;
	struct node *link;
};

struct node *head = NULL;

void push(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;				
	newnode->link = NULL;
	if(!head){
		head = newnode;
	}
	else{
		struct node *temp=head;
		while(temp->link!=NULL){
			temp = temp->link;
		}
		temp->link = newnode;
	}
}

void append(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data= data;
	if(!head){
		head=newnode;	
	}
	else{
		newnode->link = head;
		head = newnode;			
	}
}

void insert(int after,int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	if(!head){
		head=newnode;	
	}
	else{
		struct node *temp = head;
		while(temp != NULL){
			if(temp->data == after){
				newnode->link = temp->link;
				temp->link = newnode;
				found = 1;
				break;
			}
			
			temp = temp->link;		
		}
		if(found == 0){
			newnode = NULL;
			printf("%d element not found !",after);
		}
	}
}

void display(){
	struct node *temp= head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp=temp->link;
	}
}

int main(){
	push(1);
	push(2);
	push(4);
	insert(2,3);
	display();
	return 0;
}

