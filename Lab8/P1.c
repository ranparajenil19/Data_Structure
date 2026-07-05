#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;


struct Node* firstList(struct Node* head1 , int first_data){
    struct Node* new_node1 = (struct Node *)malloc(sizeof(struct Node));
    new_node1->data = first_data;
    new_node1->next = head1;
    head1 = new_node1;
    return head1;
}

struct Node* secondList(struct Node* head2 , int second_data){
     struct Node* new_node2 = (struct Node *)malloc(sizeof(struct Node));
     new_node2->data = second_data;
     new_node2->next = head2;
     head2 = new_node2;
     return head2;

}

void compareList(struct Node* head1 , struct Node* head2){

    while(head1!=NULL || head2!=NULL){
        if(head1->data != head2->data){
            printf("Lists Are Not Same \n");
            return;
        }
        head1 = head1->next;
        head2 =  head2->next;
    }
    
    printf("Lists Are Same ");
    
}
int main(){
    
    int list1_range , list2_range;


    printf("How Many data you want for list1 & list2 : \n");
    scanf("%d %d",&list1_range,&list2_range);

    if(list1_range!=list2_range){
        printf("List are Not Same: ");
        return 0;
    }

    for(int i=1 ; i<=list1_range ; i++){
        int data1;
        printf("Enter Data Of First List: \n");
        scanf("%d",&data1);
        head1 = firstList(head1 , data1);
    }

    for(int i=1 ; i<=list2_range ; i++){
        int data2;
        printf("Enter Data Of Second List: \n");
        scanf("%d",&data2);
        head2 = secondList(head2 , data2);
        
        
    }
    compareList(head1 , head2);


}