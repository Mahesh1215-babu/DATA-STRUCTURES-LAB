#include <stdio.h>
	if(top==NULL) {
		new_node->data=x;
		new_node->next=top;
		top=new_node;
		printf("Successfully pushed.\n");
	}
	else{
		new_node->data=x;
		new_node->next=top;
		top=new_node;
		printf("Successfully pushed.\n");
	}
	
}
void display() {
	if(top==NULL){
		printf("Stack is empty.\n");
		return;
	}
	printf("Elements of the stack are : ");
	struct stack* temp = top;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}




	// write your code here to display the stack elements


int main() {
	int op, x;
	while(1) {	
	printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
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
