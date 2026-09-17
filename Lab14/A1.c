#include <stdio.h>
#include <stdlib.h>

struct Node
{
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
    if(top==NULL){
        return '\0';
    }

    struct Node* temp = top;
    char popped_val = temp->data;
    top = top->next;
    free(temp);
    return popped_val;
}
int isEmpty(){
    return top==NULL;
}

void validParenthesis(char *str){
    int i=0;

    if(str[i]=='\0'){
        printf("Empty String");
        return;
    }
    while(str[i]!='\0'){

        char ch = str[i];

        if(ch=='('||ch=='{'||ch=='['){
            push(ch);
        }
        else if(ch==')'||ch=='}'||ch==']')
        {
            if (isEmpty()) {
                printf("incorrect\n");
                return;
            }

            char open = pop();
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                printf("incorrect\n");
                return;
            }
        }
        i++;
        
    }
    if(isEmpty()){
        printf("Correct");
    }
    else{
        printf("Incorrect");
    }
}


int main(){

    char string[100];
    printf("Enter the Bracket: ");
    scanf("%s",string);

    validParenthesis(string);

}