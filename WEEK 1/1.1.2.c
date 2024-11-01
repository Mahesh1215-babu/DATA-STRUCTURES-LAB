#include <stdlib.h>
#include <stdio.h>
#include "QueueOperations.c"
int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}

#include<stdio.h>
int front = -1;
int rear = -1;

void enqueue(int x){
	if(front == 0 && (rear == MAX -1)) {
		printf("Queue is full\n");
		return;
	}
	else{
		if(front == -1){
			front = 0;
		}
		rear=rear+1;
		queue[rear] = x;
		printf("Successfully inserted.\n");
	}
}
void dequeue() {
	if(front == -1 || front>rear) {
		printf("Queue is underflow.\n");
	} else {
		printf("Deleted element = %d\n",queue[front]);
		front=front+1;
			}
}

void display() {
	if(front == -1 || front>rear ) {
		printf("Queue is empty.\n");
	} else {
		printf("Elements in the queue : ");
		for(int i = front; i <= rear; i++) {
			printf("%d ",queue[i]);
		}
		printf("\n");
		}
}
void size() {
	int x=0;
	if(front == -1||front>rear)
		printf("Queue size : %d\n",x);
	else{
		x=rear-front+1;
		printf("Queue size : %d\n",x);
	}


}

void isEmpty() {
	if(front == -1 || front>rear) {
		printf("Queue is empty.\n");
	} else {
		printf("Queue is not empty.\n");
	}

}
