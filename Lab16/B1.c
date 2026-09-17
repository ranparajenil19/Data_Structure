#include <stdio.h>
#include <string.h>
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
int perform_op(int op2 , int op1 , char temp){
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
int evo_prefix(char prefix[]){
    top = -1;
    int value = 0;
    
    for(int i=strlen(prefix)-1 ; i>=0 ; i--){
        if(isdigit(prefix[i])){
            push(prefix[i]-'0');
        }

        else{
            int op1 = pop();
            int op2 = pop();

            value = perform_op(op1,op2,prefix[i]);
            push(value);
        }
       
    }
    return pop();
}
int main(){

    char prefix[n];
    printf("Enter prefix Expression: ");
    scanf("%s",prefix);

    int result = evo_prefix(prefix);
    printf("Result: %d",result);
}