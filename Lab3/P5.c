#include <stdio.h>
int main(){

    int n,i,j;
    
    printf("Enter a size of an array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0 ; i<n ;i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }
    for(i=0 ; i<n-1 ;i++){
        for(j=0 ; j<n-i-1 ;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(i=0 ; i<n ; i++){
        if(arr[i]==arr[i+1]){
            printf("Duplicate Number Exits");
            return 0;
        }

    }
    printf("Duplicate Number Doesn't Exits");
}