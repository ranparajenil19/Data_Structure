#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int cqueue[MAX];
int front = -1;
int rear = -1;

void insert(int val) {
    
    if ((rear + 1) % MAX == front) {
        printf("\nCircular Queue Overflow!\n");
        return;
    }

   
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; 
    }

    cqueue[rear] = val;
    printf("Successfully inserted %d\n", val);
}

void delete_element() {
    
    if (front == -1) {
        printf("\nCircular Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", cqueue[front]);

    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; 
    }
}

void display() {
    if (front == -1) {
        printf("\nCircular Queue is Empty!\n");
        return;
    }

    printf("\nCircular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX; 
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}