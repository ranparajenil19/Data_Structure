#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertFirst(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = head;
    
    if (head != NULL) {
        head->prev = new_node;
    }
    
    head = new_node;
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

struct Node* deleteFromSpecific(struct Node* head, int position) {
    if (head == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    
    struct Node* temp = head;
    
    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return head;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
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
    int choice, data, position;
    
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Delete from Specific Position\n");
        printf("3. Insert at End\n");
        printf("4. Display All Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insertFirst(head, data);
                break;
                
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromSpecific(head, position);
                break;
                
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertLast(head, data);
                break;
                
            case 4:
                display(head);
                break;
                
            case 5:
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}