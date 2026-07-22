#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

char pop() {
    if (top == NULL) {
        return '\0';
    }
    struct Node* temp = top;
    char popped_val = temp->data;
    top = top->next;
    free(temp);
    return popped_val;
}

int isStackEmpty() {
    return top == NULL;
}

void isEqual(char* str) {
    int i = 0;

    if(str[i]!='a'){
        printf("Invalid String");
        return;
    }
    while (str[i] != '\0') {
        if(str[i]!='a' && str[i]!='b'){
            printf("Invalid String");
            return;
        }

        if(str[i]=='a'){
            push('a');
        }
        if(str[i]=='b'){
            pop();
        }

        i++;
    }

    if(isStackEmpty()){
        printf("Condition Matched\n");
    }
    else{
        printf("Not");
    }
}

int main() {
    char inputString[100];

    printf("Enter string to recognize: ");
    scanf("%s", inputString);

    isEqual(inputString);

    return 0;
}