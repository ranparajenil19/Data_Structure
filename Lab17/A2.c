#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("\nMemory Allocation Failed (Overflow)!\n");
        return;
    }
    new_node->data = val;
    new_node->next = NULL;

    
    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Successfully enqueued %d\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow!\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("\nQueue is Empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("\nQueue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- QUEUE MENU (LINKED LIST) ---");
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