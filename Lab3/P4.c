#include <stdio.h>
int main(){

    int n , i , min_value , max_value;
    
    printf("Enter a size of an array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0 ; i<n ;i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }
    min_value = arr[0];
    max_value = arr[0];

    for(i=1 ; i<n ;i++){
        if(arr[i] > max_value){
            max_value = arr[i];
        }
        if(arr[i] < min_value){
            min_value = arr[i];
        }
    }
    printf("Max Value %d ", max_value);
    printf("\n");
     printf("Min Value %d ", min_value);

} 