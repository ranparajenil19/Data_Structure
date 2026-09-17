#include <stdio.h>
#include <ctype.h>
#define n 50
int top = -1;
int stack[n];

void push(int val){
    if(top >= n-1){
        printf("Stack Overflow:\n");
        return;
    }
    stack[++top] = val;
}
int pop(){
    if(top<0){
        printf("Stack Underflow\n");
        return 0;
    }
    int val = stack[top--];
    return val;
}
int perform_op(int op1 , int op2 , char temp){
    if(temp=='+'){
        return op2+op1;
    }
    if(temp=='-'){
        return op2-op1;
    }
    if(temp=='*'){
        return op2*op1;
    }
    if(temp=='/'){
        return op2/op1;
    }
}
int evo_postfix(char postfix[]){
    top = -1;
    int value = 0;
    int i=0;
    while(postfix[i]!='\0'){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0');
        }

        else{
            int op1 = pop();
            int op2 = pop();

            value = perform_op(op1,op2,postfix[i]);
            push(value);
        }
        i++;
    }
    return pop();
}
int main(){

    char postfix[n];
    printf("Enter Postfix Expression: ");
    scanf("%s",postfix);

    int result = evo_postfix(postfix);
    printf("Result: %d",result);
}