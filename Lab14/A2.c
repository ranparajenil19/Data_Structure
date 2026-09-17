#include<stdio.h>
#include <stdlib.h>
struct Node{
    char data;
    struct Node* next;
};
struct Node* top = NULL;
void push(char value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL){
        return;
    }
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}
char pop(){
    if(top == NULL){
        return '\0';
    }
    struct Node* temp = top;
    char popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}
int isEmpty(){
    return top == NULL;
}
void remove_star(char* str){
    int i=0;
    if(str[i]=='\0'){
        printf("Empty String\n");
        return;
    }
    while(str[i]!='\0'){
        if(str[i]!='*'){
            push(str[i]);
        }
        else{
            pop();
        }
        i++;
    }
    char ch[100];
    int len = 0;

    while(!isEmpty()){
        ch[len++] = pop();
    }
    ch[len] = '\0';
    for(int i=len-1 ; i>=0 ; i--){
        printf("%c",ch[i]);
    }
}
int main(){
    char string[100];
    printf("Enter a String: ");
    scanf("%s",string);

    remove_star(string);
}