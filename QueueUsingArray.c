#include<stdio.h>
#define MAX 10
int front =-1,rear = -1;
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
int queue[MAX];
void enqueue(int x){
    if(front == 0 && rear==MAX-1){
        printf("Queue is of Maximum size.\n");
        return ;
    }else{
        if(front == -1){
            front = 0;
        }
        rear = rear+1;
        queue[rear]=x;
        printf("Successfully inserted\n");
    }
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("queue is underflow\n");
    }
    else{
        printf("The deleted value =%d\n",queue[front]);
        front=front+1;
    }
}

void display(){
     if(front==-1 || front>rear){
        printf("queue is underflow\n");
    }
    else{
     printf("The elements in the Queue are: \n");
     for(int i =front;i<=rear;i++){
        printf("%d ",queue[i]);
     }
     printf("\n");
    }
}

void size(){
    int x =0;
     if(front==-1 || front>rear){
        printf("the size of queue is %d\n",x);
    }
    else{
        x = rear-front +1;
        printf("the size of the queue is %d\n",x);
    }
}
void isempty(){
     if(front==-1 || front>rear){
        printf("queue is empty\n");
    }
    else{
     printf("queue is not empty\n");
    }
}