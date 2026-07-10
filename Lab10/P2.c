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
struct Node* swapNode(struct Node* head,int range,int k){
   int i = k ;
   int count = 1;
   int j = range - k+1;
   struct Node* tempNode = head;
   struct Node* temp1;
   struct Node* temp2;


   while(tempNode!=NULL){
        if(count==i){
            temp1 = tempNode;
        }
        if(count==j){
            temp2 = tempNode;
           
        }
        count++;
        tempNode = tempNode->next;
    }
    int temp = temp2->data;
    temp2->data = temp1->data;
    temp1->data = temp;

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
    struct Node* temp = swapNode(head,range,2);
     while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}