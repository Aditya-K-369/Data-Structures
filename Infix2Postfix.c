#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define STACK_MAX_SIZE 20
int top = -1;
int stack[STACK_MAX_SIZE];

void main(){
    char *e,E[20];
    printf("Enter the expression: \n");
    scanf("%s",E);
    e = E;
    convertInfix(e);
}

int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push (char x){
    if(top==STACK_MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }else{
        top+=1;
        stack[top]= x;
    }
}
char pop(){
    if(top == -1){
        printf("Stack underflow\n");
        exit(1);
    }else{
        char ch;
        ch = stack[top];
        top -=1;
        return ch;
    }
}

char priority( char x){
  switch(x){
    case '+':
    case '-':
    return 1;
    case '*':
    case '/':
    case '%':
    return 2;
    case '(':
    return 0;
    default:
    return -1;
  }
}
void convertInfix(char *e){
    int j = 0;
    char c,Postfix[STACK_MAX_SIZE];
    for(int i = 0;e[i]!='\0';i++){
        c = e[i];
        if(isalnum(c)){
            Postfix[j]=c;
            j+=1;
        }else if (c =='('){
            push(c);
        }else if (c==')')
        {
        while(!isEmpty()&&stack[top]!='('){
            Postfix[j]=pop();
            j+=1;
        }
        if(top!=-1 && stack[top]=='('){
            pop();
        }else{
            printf("Invalid infix expression: Unbalanced paranthesis\n");
            exit(0);
        }
        }else if (strchr("+-*/%",c)){
            while(top!=-1&& priority(c)<=priority(stack[top])){
                Postfix[j]= pop();
                j+=1;
            }
            push(c);
        }else{
            printf("Invalid symbols in infix expression\n");
            exit(0);
        }
    }
    while(!isEmpty()){
        if(stack[top]=='('){
            printf("Invalid infix expression: Unbalanced parenthesis\n");
            exit(0);
        }
        Postfix[j++]=pop();
    }
    Postfix[j]='\0';
    printf("Postfix expression: %s\n",Postfix);
}