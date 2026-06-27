#include<stdio.h>
#include<stdlib.h>
int main(){

    int n;
    int sum=0;

    int *pn = &n;
    int *psum = &sum;

    printf("Enter a Number: ");
    scanf("%d",pn);

    for(int k=1 ; k<=n ; k++){
       *psum = *psum + k;
    }

    printf("Sum = %d",*psum);
}