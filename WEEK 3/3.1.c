#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define STACK_MAX_SIZE 20
#include "Infix2PostfixOperation.c"
int main() {
	char exp[20];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s",exp);
	e = exp;
	convertInfix(e);
}
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define STACK_MAX_SIZE 20

char stack[STACK_MAX_SIZE];
int top = -1;
char postfix[20];

int isEmpty() {
return top == -1;
}


void push(char x) {
if (top >= STACK_MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}


char pop() {
if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int priority(char x) {
switch (x) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
}
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '^');
}

void convertInfix(char * e) {
int temp = 0;  // Index for postfix expression
    char character;
    int openParenthesisCount = 0;
    int closeParenthesisCount = 0;

    while (*e != '\0') {
        character = *e;

      
        // Check if the character is a valid operand or operator
        if (isalnum(character)) {
            postfix[temp++] = character;
        }
        // Check if the character is a valid operator
        else if (character == '(') {
            push(character);
            openParenthesisCount++;
        }
        else if (character == ')') {
            closeParenthesisCount++;
            if (closeParenthesisCount
 > openParenthesisCount) {
                printf("Invalid infix expression: unbalanced parenthesis\n");
                return;
            }
            while (stack[top] != '(') {
                postfix[temp++] = pop();
            }
            pop();  // Remove '(' from the stack
        }
        else if (isOperator(character)) {
            while (!isEmpty() && priority(stack[top]) >= priority(character)) {
                postfix[temp++] = pop();
            }
            push(character);
        }
        else {
            // If the character is not valid, print an error
            printf("Invalid symbols in infix expression\n");
            return;
        }

        e++;
    }

    // Check for unbalanced parentheses
    if (openParenthesisCount != closeParenthesisCount)
	{

printf("Invalid infix expression : unbalanced parenthesis\n");
        return;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty()) {
        postfix[temp++] = pop();
    }

    postfix[temp] = '\0';  // Null-terminate the postfix expression
    printf("Postfix expression : %s\n", postfix);
}
