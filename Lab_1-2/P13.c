#include <stdio.h>
int main(){
    int n , i=2 , sum=0;
    printf("Enter a Number:");
    scanf("%d",&n);

    for(i ; i<n ; i++ ){
        if(n%i==0){
           sum++;
        }
    }

    if(sum==0){
        printf("Number is Prime:");

    }
    else{
        printf("Number is Not prime");
    }
}