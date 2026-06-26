#include <stdio.h>
int main(){

    int n;
    printf("Enter a Number:");
    scanf("%d",&n);

    if(n&1==1){
        printf("Number is Odd");
    }
    else{
        printf("Number is Even");
    }

}