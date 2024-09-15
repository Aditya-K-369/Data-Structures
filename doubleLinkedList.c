#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct stack {
int data;
struct stack *prev;
struct stack *next;
};

typedef  struct stack *s;
s head = NULL;
s temp = NULL;

void push(int x);

void display(){
	printf("Forward traversal:\n");
	temp= head;
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
	printf("Reverse traversal:\n");
	temp = head;
	while(temp->next!= NULL){
		temp = temp->next;
	}
	while(temp!= NULL){
		printf("%d\t",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void delete(int x){
	temp = head;
	while(temp != NULL && temp->data !=x){
		temp = temp->next;
	}
	if(temp==NULL){
		printf("%d not found\n",x);
		return ;
	}
	if(head==temp){
		head = temp->next;
		if(head!=NULL)
			head->prev = NULL;
		free(temp);
	}
	if(temp->next == NULL){
		temp->prev->next = NULL;
		free(temp);
		return ;
	}

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
}


void main(){
	int n,x;
	while(1){
		printf("Operations on doubly linked list\n1. Insert \n2. Delete\n3. Display\n0. Exit\nEnter Choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
			printf("Enter number: ");
			scanf("%d",&x);
			push(x);
			break;
			case 2 :
			printf("Enter number to delete: ");
			scanf("%d",&x);
			delete(x);
			break;
			case 3: 
			display();
			break;
			case 0 :
			exit(0);
		}
	}
}

void push(int x){
	s new_node = (s)malloc(sizeof(struct stack));
	new_node->data = x;
	new_node->prev = NULL;
	new_node->next = NULL;
	if(head == NULL){
	head = new_node;
		return ;
	}else{
		temp=head;
		while(temp->next!= NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}
}
