int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				peek();
				break;
			case 6: 
				exit(0);
		}
	}
}

#define STACK_MAX_SIZE 10
int arr[STACK_MAX_SIZE];
int top = -1;
void pop() {
	int x;
	if(top<0){
		printf("Stack is underflow.");
	}
	else{
		x=arr[top];
		top=top+1;
		printf("Popped value = %d",x);
	}
}
void peek() {
	int x;
	if(top<0){
		printf("Stack is underflow.");
	}
	x=arr[top];
	printf("Peek value =%d",x);
}
void isEmpty() {
	if(top<0){
		printf("Stack is empty.");
	}
	else{
		printf("Stack is not empty.");
	}
}
void push(int element) {
	if(top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
		printf("Successfully pushed.\n");
	}
}
void display() {
	if (top < 0) {
		printf("Stack is empty.\n");
	} else {
		printf("Elements of the stack are : " );
		for(int i = top; i >= 0; i--) {
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
}
