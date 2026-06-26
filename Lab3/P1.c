#include <stdio.h>
int main(){

    int n,i;
    
    printf("Enter a size of an array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0 ; i<n ;i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }
     for(i=0 ; i<n ;i++){
        printf("%d ",arr[i]);
    }
}