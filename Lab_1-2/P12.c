#include <stdio.h>
int main(){

    int n , i=1 , sum=0;
    printf("Enter a Number:");
    scanf("%d",&n);

    for(i=1 ; i<n ; i++ ){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n){
        printf("Number is perfect");
    }
    else{
        printf("Number is Not perfect");
    }
}