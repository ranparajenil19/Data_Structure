#include <stdio.h>
int main(){
    int n , sum=0;
    printf("Enter a Number:");
    scanf("%d",&n);

    int temp=n;

    while(temp!=0){
        int rem = temp%10;
        sum = sum*10  +rem;
        temp = temp/10;
    }
    if(sum==n){
        printf("Number is Palindrome");

    }
    else{
        printf("Number is not Palindrome");
    }

}