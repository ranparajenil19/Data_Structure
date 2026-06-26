#include <stdio.h>
int main(){

    int n,m,i,sum=0;
    
    printf("Enter a staring and ending number: ");
    scanf("%d %d",&m,&n);
    int k =n-m+1;
    int arr[k];
    for(i=0 ; i<k ;i++){
        arr[i] = m;
         sum+=arr[i];
         m++;
    }
    printf("Sum of All Element : %d ",sum);
}