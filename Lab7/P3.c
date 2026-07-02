#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* insertFirst(struct Node* head , int new_data){
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = head;

    head = new_node;

    return head;
}

int main(){

    struct Node* head = NULL;

    head = insertFirst(head , 10);
    head = insertFirst(head , 60);
    head = insertFirst(head , 20);

    struct Node* temp = head;
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}