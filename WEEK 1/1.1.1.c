#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 10
#include "StackOperations.c"

int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
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

#define MAX 8
void push(int element){
	if(top>MAX){
		printf("Stack is overflow.\n");
	}
	else{
		top++;
		stack[top]=element;
		printf("Successfully pushed.\n");
	}
}
void display(){
	int i;
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Elements of the stack are : ");
		for(i=top;i>=0;i--){
			printf("%2d ",stack[i]);
		}
		printf("\n");
	}
}
void pop(){
	if(top==-1){
		printf("Stack is underflow.\n");
	}
	else{
		printf("Popped value = %d\n",stack[top]);
		top--;
	}
}
void peek(){
	if(top==-1){
		printf("Stack is underflow.\n");
	}
	else{
		printf("Peek value = %d\n",stack[top]);
}
}


void isEmpty() {
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Stack is not empty.\n");
	}
}