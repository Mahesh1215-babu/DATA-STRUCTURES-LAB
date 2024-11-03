#include <stdio.h>
void print(int arr[], int n) {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if (i<n-1) {
        }
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    char choice;
    int element;

    do {
        printf("I - Insert\nD - Delete\nP - Print\nQ - Quit\n");
        printf("Enter option: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'I':
            case 'i':
                printf("Element to insert: ");
                scanf("%d", &element);
                insert(arr, &n, element);
                break;
            case 'D':
            case 'd':
                printf("Element to delete: ");
                scanf("%d", &element);
                delete(arr, &n, element);
                break;
            case 'P':
            case 'p':
                print(arr, n);
                break;
            case 'Q':
            case 'q':
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
