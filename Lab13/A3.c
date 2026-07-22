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

int isPatternValid(char* str) {
    int i = 0;

    while (str[i] != 'c') {
        if (str[i] == '\0') {
            return 0;
        }
        push(str[i]);
        i++;
    }

    i++;

    while (str[i] != '\0') {
        char popped_char = pop();
        if (str[i] != popped_char) {
            while (!isStackEmpty()) {
                pop();
            }
            return 0;
        }
        i++;
    }

    return isStackEmpty();
}

int main() {
    char inputString[100];

    printf("Enter string to recognize: ");
    scanf("%s", inputString);

    if (isPatternValid(inputString)) {
        printf("String is Accepted\n");
    } else {
        printf("String is Rejected\n");
    }

    return 0;
}