#include<stdio.h>
#include<stdlib.h>
struct queue {
int data;
struct queue *next;
};
typedef struct queue *Q;
Q front=NULL,rear = NULL;

void enqueue(int x){
    Q temp = NULL;
    temp = (Q)malloc(sizeof(struct queue));
    if(front==NULL){
        temp->data = x;
        temp->next = NULL;
        front = temp;
        rear = temp;
    }else{
        temp->data = x;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
    printf("Successfully inserted\n");
}

void dequeue(){
    if(front ==NULL){
        printf("Queue is empty");
    }else{
        printf("Deleted element is %d\n",front->data);
        Q temp = NULL;
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        Q temp = front;
        printf("The elements of queue are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void size(){
    int x = 0;
    if(front == NULL){
        printf("The size of queue is %d\n",x);
        return;
    }
    Q temp = front;
    while(temp!=NULL){
        x = x+1;
        temp = temp->next;
    }
    printf("The size of queue is %d\n",x);
}

void isempty(){
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }
}


void main(){
    int op,n;
    while(1){
    printf("1.enqueue 2.dequeue 3.display 4.size 5.isempty 6.exit");
    printf("Enter your option: ");
    scanf("%d",&op);
    switch (op)
    {
    case 1 :
    printf("Enter the element: ");
    scanf("%d",&n);
    enqueue(n);
    break;
    case 2:
    dequeue();
    break;
    case 3:
    display();
    break;
    case 4 :
    size();
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