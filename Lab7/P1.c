#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node* next;
};
void insertAtFirst(struct Node** head , int new_data ){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = new_data;
        new_node->next = *head;

        *head = new_node;
}
void insertAtLast(struct Node** head , int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* save = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head==NULL){
        *head = new_node;
        return;
    }
    while (save->next!=NULL){
        save = save->next;
    }
    
    save->next = new_node;
    
}
void insertInSortOrder(struct Node** head , int new_data ){

    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* save = *head;

    new_node->data = new_data;
    if(*head==NULL){
        new_node->next = NULL;
        *head = new_node;
        return;

    }
    if(new_node->data <= (*head)->data){
        new_node->next = *head;
        *head  = new_node;
        return;
    }
    
   while(save->next!=NULL && save->next->data < new_data ){
            save = save->next;
   }
    new_node->next = save->next;
    save->next = new_node;
}
int main(){
        struct Node* head = NULL;

        insertAtFirst(&head , 10);
        insertAtFirst(&head , 20);
        insertAtFirst(&head , 30);

        insertAtLast(&head , 50);

        insertInSortOrder(&head , 40);

        struct Node* temp = head;
        while(temp!=0){

            printf("%d -> " , temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        return 0;
}