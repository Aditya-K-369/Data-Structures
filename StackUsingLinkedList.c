#include<stdio.h>
#include<stdlib.h>
struct stack {
int data;
struct stack *next;
};
typedef  struct stack *stk;
stk temp,top = NULL;

void push(int x){
    struct stack *new_node = (stk)malloc(sizeof(struct stack));
    if(top==NULL){
    new_node->data = x;
    new_node->next = NULL;
    top = new_node;
    printf("Successfully pushed");
    }
    else{
    new_node->data = x;
    new_node->next = top;
    top = new_node;
    printf("Successfully pushed");
    }
}

void pop(){
    if(top==NULL){
        printf("Stack is underflow");
        return;
    }
    else{
    temp = top;
    top = top->next;
    temp->next = NULL;
    printf("popped value = %d\n",temp->data);
    free(temp);
    }
}

void isempty(){
    if(top==NULL){
        printf("Stack is empty");
    }else{
        printf("Stack is not not empty");
    }
}
void peek(){
    if(top==NULL){
        printf("Stack is underflow");
    }else{
        printf("The peek value is %d",top->data);
    }
}

void display(){
    if(top==NULL){
    printf("Stack is underflow");
    return;
    }
    else{
        printf("The elements of stack are: ");
        temp = top;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
    int op,n;
    while(1){
    printf("1.push 2.pop 3.display 4.peek 5.isempty 6.exit");
    printf("Enter your option: ");
    scanf("%d",&op);
    switch (op)
    {
    case 1 :
    printf("Enter the element: ");
    scanf("%d",&n);
    push(n);
    break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    case 4 :
    peek();
    break;
    case 5 :
    isempty();
    break;
    case 6:
    exit(0); 
    default:
        break;
    }    
    }
}