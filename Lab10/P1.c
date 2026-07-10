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
struct Node* sort(struct Node* head){
   struct Node* i;
   struct Node* j;

   for(i=head ; i->next!=NULL ; i=i->next){
        for(j=i->next ; j!=NULL ; j = j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
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
    struct Node* temp = sort(head);
     while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}