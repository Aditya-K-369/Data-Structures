#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
void evaluatePostfix(char* expr) {
    int i = 0;
    int operand1, operand2, result;

    while (expr[i] != '\0') {
        // If the character is a digit, push it to the stack
        if (isdigit(expr[i])) {
            push(expr[i] - '0'); // Convert char to int
        }
        // If the character is an operator, pop two values and apply the operator
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            if (top < 1) {
                printf("Stack underflow\n");
                return;
            }
            operand2 = pop();
            operand1 = pop();

            switch (expr[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        return;
                    }
                    result = operand1 / operand2; 
                    break;
            }
            push(result);
        }
        // If the character is invalid, it's an invalid postfix expression
        else {
            printf("Invalid postfix expression\n");
            return;
        }
        i++;
    }

    // After evaluation, there should be exactly one element in the stack
    if (top == 0) {
        printf("Evaluated expression: %d\n", pop());
    } else {
        printf("Invalid postfix expression\n");
    }
}

int main() {
    char expr[100];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", expr);

    // Evaluate the postfix expression
    evaluatePostfix(expr);

    return 0;
}
