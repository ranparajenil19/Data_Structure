#include <stdio.h>

#define n 50

struct Element {
    int value;
    int priority;
};

struct Element queue[n];
int front = -1;
int rear = -1;

void insert(int value, int p) {
    if (rear >= n - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
        queue[rear].value = value;
        queue[rear].priority = p;
    } else { 
        int i;
        
        for (i = rear; i >= front && queue[i].priority > p; i--) {
            queue[i + 1] = queue[i];
        }
        queue[i + 1].value = value;
        queue[i + 1].priority = p;
        rear++;
    }
    printf("Element Inserted\n");
}

int delete_element() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int val = queue[front].value;
    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;
    }
    return val;
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nQueue elements (Val, Priority): ");
    for (int i = front; i <= rear; i++) {
        printf("[%d, P:%d] ", queue[i].value, queue[i].priority);
    }
    printf("\n");
}

int main() {
    insert(10, 2);
    insert(20, 1); 
    insert(30, 3);
    display();

    printf("Deleted element: %d\n", delete_element());
    display();

    return 0;
}