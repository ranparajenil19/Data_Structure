#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* head = NULL;

struct Node* list(struct Node* head , int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    return head;
}
struct Node* copyList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
    new_head->data = head->data;
    new_head->next = NULL;

    struct Node* current = head->next;
    struct Node* last_copied = new_head;

    while (current != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = current->data;
        new_node->next = NULL;

        last_copied->next = new_node;
        last_copied = new_node;

        current = current->next;
    }

    return new_head;
}

int main(){
    int range;
    printf("How Many Nodes : \n");
    scanf("%d" , &range);

    for(int i=1 ; i<=range ; i++){
        int data;
        printf("Enter Data Of Node: \n");
        scanf("%d",&data);

        head = list(head,data);

    }
    struct Node* temp = copyList(head);
     while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
