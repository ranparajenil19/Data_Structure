#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteAlternate(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        
        current->next = temp->next;
        
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
        
        free(temp);
        current = current->next;
    }

    return head;
}

struct Node* insertLast(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (head == NULL) {
        new_node->prev = NULL;
        return new_node;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    head = insertLast(head, 40);
    head = insertLast(head, 50);

    printf("Original List:\n");
    display(head);

    head = deleteAlternate(head);

    printf("List after deleting alternate nodes:\n");
    display(head);

    return 0;
}