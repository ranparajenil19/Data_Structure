#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* insertFirst(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* insertLast(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (head == NULL) {
        return new_node;
    }
    
    struct Node* temp = head; 
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    free(temp);
    return head;
}

struct Node* deleteFromSpecific(struct Node* head, int x) {
    if (head == NULL) {
        printf("Underflow!\n");
        return NULL;
    }
    
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if (temp->data == x) {
        head = temp->next;
        free(temp);
        return head;
    }
    
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element %d Not Found\n", x);
        return head;
    }
    
    prev->next = temp->next;
    free(temp); 
    return head;
}
int  count(struct Node* head){
    int count = 0;
     if(head==NULL){
        printf("Under Flow: ");
        return -1;
    }
    struct Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;

    }
    return count;

}

int main() {
    struct Node* head = NULL;
    
    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);
    printf("\nAfter Insert At First:\n");
    display(head);
    
    head = deleteFirst(head);
    printf("\nAfter Delete At First:\n");
    display(head);
    
    head = insertLast(head, 40);
    printf("\nAfter Insert At Last:\n");
    display(head);
    
    head = deleteLast(head);
    printf("\nAfter Delete At Last:\n");
    display(head);
    
    head = deleteFromSpecific(head, 10);
    printf("\nAfter Delete Specific (10):\n");
    display(head);

    int count_main = count(head);
    printf("\nAfter count :\n");
    printf("%d",count_main);
    
    return 0;
}