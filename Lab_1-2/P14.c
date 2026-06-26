#include <stdio.h>
int main(){
    int n , sum=1;
    printf("Enter a Number:");
    scanf("%d",&n);

    int i=1;
    for(i=1 ; i<=n ;i++){
        sum*=i;
    }
    printf("Factorial = %d",sum);

}