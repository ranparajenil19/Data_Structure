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

int peek(){
    return stack[top];
}
int sortUsingStack(int arr[] , int size){
    int i=1 , j=0;
    int b[size];
    push(arr[0]);

    for(i=1 ; i<size ; i++){
        if(arr[i]>peek()){
            b[j++] = pop();
            push(arr[i]);
        }
        else{
            push(arr[i]);
        }
    }
    while(top!=-1){
        b[j++] = pop();
    }
    
    for(i=0 ; i<size-1 ; i++){
        if(b[i]>b[i+1]){
            return 0;
        }
        
    }
    return 1;
}
int main(){

    int size;
   
    printf("Enter Size Of an Array: \n");
    scanf("%d",&size);

     int arr[size];
    for(int i=0 ; i<size ; i++){
        printf("Enter Element: ");
        scanf("%d",&arr[i]);

    }
    int result = sortUsingStack(arr,size);
    if(result==1){
        printf("YES");
    }
    else{
        printf("NO");
    }
}