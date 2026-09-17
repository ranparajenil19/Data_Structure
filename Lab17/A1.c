#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear >= MAX - 1) {
        printf("\nQueue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    rear++;
    queue[rear] = val;
    printf("Successfully enqueued %d\n", val);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow!\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    front++;

    
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- QUEUE MENU (ARRAY) ---");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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