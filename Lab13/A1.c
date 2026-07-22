#include <stdio.h>
#include <stdlib.h>
#define N 5

int top = -1;
int s[N];

void push(int x){
    if(top>=N-1){
        printf("Stack Overflow\n");
        return;
    }

    top = top + 1;
    s[top] = x;
}
int pop(){
    if(top<=-1){
        printf("Stack Underflow");
        return -1;
    }
    top--;
    return s[top+1];
    
}
int peep(int i){
    if(s[top-i+1]<=-1){
        printf("Not Available");
        return -1;
    }

    return s[top-i+1];
}

void change(int x , int i){
    if(s[top-i+1]<=-1){
        printf("Not Available");
        return ;
    }

    s[top-i+1] = x;
    return;
    
}
void display(){
    if(top==-1){
        printf("Under Flow");
    }
    for(int i=top ; i>=0 ; i--){
        printf("%d\t",s[i]);
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    pop();
    pop();

    change(30,2);

    display();
}