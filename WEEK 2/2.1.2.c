#include <stdlib.h>
}

void isEmpty() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

// Function to get the size of the queue
void size() {
    int count = 0;
    Q temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Queue size : %d\n", count);
}
int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is empty 5.Size 6.Exit\n");
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
