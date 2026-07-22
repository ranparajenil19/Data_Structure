#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* head = NULL;
struct Node* last = NULL;

struct Node* cir_insertFirst(struct Node* head,int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if(head==NULL){
        new_node->next = new_node;
        head = new_node;
        last = new_node;
    }
    else{
        new_node->next = head;
        last->next = new_node;
        head = new_node;
    }
    return head;
    
}
struct Node* cir_insertLast(struct Node* head,int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if(head==NULL){
        new_node->next = new_node;
        head = new_node;
        last = new_node;
    }
    else{
        new_node->next = head;
        last->next = new_node;
        last = new_node;
    }
    return head;
    
}
struct Node* deleteFromSpecific(struct Node* head, int position) {
    if (head == NULL) {
        printf("Underflow!\n");
        return NULL;
    }

    struct Node* temp = head;

    if (position == 1) {
        if (head->next == head) {
            free(head);
            last = NULL;
            return NULL;
        } else {
            last->next = head->next;
            head = head->next;
            free(temp);
            return head;
        }
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Position out of bounds\n");
            return head;
        }
    }

    prev->next = temp->next;

    if (temp == last) {

        last = prev;
    }
    

    free(temp);
    return head;
}

int main(){

    int range;
    printf("How Many Nodes : \n");
    scanf("%d" , &range);

    for(int i=1 ; i<=range ; i++){
        int data;
        printf("Enter Data Of Node: \n");
        scanf("%d",&data);

        head = cir_insertFirst(head,data);

    }
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(back to head)\n");
    }
    
}