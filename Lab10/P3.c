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
struct Node* gcd(struct Node* head){
    struct Node* temp = head;
    int min=0 , i=0 , gcd=0;

    while(temp!=NULL && temp->next!=NULL){
        min = (temp->data < temp->next->data)?temp->data:temp->next->data;
        for(i=1 ; i<=min ; i++){
            if(temp->data%i==0 && temp->next->data%i==0){
                gcd = i;
            }
        }
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->data = gcd;
        temp = temp->next->next;
    }
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

        head = list(head,data);

    }
    struct Node* temp = gcd(head);
     while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}