#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert a new node at the end
void append(struct Node** head_ref, int data) {
    struct Node* new_node = createNode(data);
    struct Node* last = *head_ref;

    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Insert the new node at the end
    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the node with the given key is not found
    if (temp == NULL) {
        printf("%d not found\n", key);
        *head_ref = temp->next;
    }

    // Change the next of previous node, if it exists
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Change the prev of next node, if it exists
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    // Change the prev of next node, if it exists
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Free the memory of the node
    free(temp);
}

void traverseForward(struct Node* node) {
    printf("Forward traversal:\n");
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->next;
    }
    printf("\n");
}

void traverseBackward(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // Move to the last node
    while (node->next != NULL) {
        node = node->next;
    }

    // Traverse in reverse
    printf("Reverse traversal:\n");
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("Operations on doubly linked list\n");
        printf("1. Insert \n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &value);
                append(&head, value);
                break;
            
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 3:
                traverseForward(head);
                traverseBackward(head);
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("");
                break;
        }
    }

    return 0;
}
