#include <stdio.h>
#include<stdlib.h>

#define Max 5
int stack[Max];
int top=-1;

void push(int value){
    if(top>=Max-1){
        printf("Stack Is Full\n");
    }
    else{
        top++;
        stack[top] = value;
        printf("Pushed %d\n",value);
    }
}
int pop(){
    if(top==-1){
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        int value = stack[top];
        top--;

        return value;

    }
}
int peek(){
    if(top==-1){
        printf("Stack is Empty\n");
        return -1;
    }
        return stack[top];
    
    
}
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("--- Current Stack Structure ---\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("-------------------------------\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    display();

    printf("Popped element: %d\n", pop());
    display();

    return 0;
}