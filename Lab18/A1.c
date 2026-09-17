#include <stdio.h>
#define n 50
int queue[n];
int front = -1;
int rear = -1;

void insert_rear(int value){
    if(rear>=n-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1){
        front = 0;
    }
    queue[++rear] = value;
    printf("Element Inserted: \n");

}
int delete_front(){
    if(front==-1){
        printf("Queue UnderFlow\n");
        return -1;
    }
    int val = queue[front++];
    if(front==rear){
        front = rear = -1;
    }
    
    return val;
}
void insert_front(int value){
    if(front==0){
        printf("Queue OverFlow\n");
        return;
    }
    if(front==-1){
        front = rear = -1;
    }
    else{
        front--;
    }
    queue[front] = value;

}
int delete_rear(){
    if(rear==-1){
        printf("Queue UnderFlow\n");
        return -1;
    }
    int val = queue[rear];
    if(front==rear){
        front = rear = 0;
    }
    else
    {
        rear--;
    }
    return val;
    
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
int main(){
        insert_rear(10);
    insert_rear(20);
    insert_front(5);
    display();

    printf("Deleted from front: %d\n", delete_front());
    printf("Deleted from rear: %d\n", delete_rear());
    display();

    return 0;
}