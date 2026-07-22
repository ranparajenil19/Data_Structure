#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;
struct Node* last = NULL;

struct Node* cir_insertLast(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if(head == NULL) {
        new_node->next = new_node;
        head = new_node;
        last = new_node;
    } else {
        new_node->next = head;
        last->next = new_node;
        last = new_node;
    }
    return head;
}

void split(struct Node* head) {
    if(head == NULL) {
        return;
    }
    else if(head == last) {
        printf("Not split\n");
        return;
    }

    struct Node* fast = head;
    struct Node* slow = head;

    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast->next->next == head) {
        fast = fast->next;
    }

    struct Node* head2 = slow->next;
    
    fast->next = head2;
    slow->next = head;

    printf("\nFirst Circular Split List: ");
    struct Node* temp1 = head;
    do {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    } while(temp1 != head);
    printf("(back to head1)\n");

    printf("Second Circular Split List: ");
    struct Node* temp2 = head2;
    do {
        printf("%d -> ", temp2->data);
        temp2 = temp2->next;
    } while(temp2 != head2);
    printf("(back to head2)\n");
}

int main() {
    int range;
    printf("How Many Nodes : \n");
    scanf("%d", &range);

    for(int i = 1; i <= range; i++) {
        int data;
        printf("Enter Data Of Node: \n");
        scanf("%d", &data);
        head = cir_insertLast(head, data);
    }
    
    split(head);
    return 0;
}