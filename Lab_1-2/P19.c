#include <stdio.h>
int main(){

    int n,sum=0,ans=0,i;
    printf("Enter a value of n: ");
    scanf("%d",&n);

    for(i=1 ; i<=n ;i++){

        sum=0;
        sum = (i*(i+1))/2;
        ans+=sum;
    }
    printf("Answer : %d" , ans);
}