#include<stdio.h>
int main(){

    int i,n,size;
    printf("Enter a size of an array: ");
    scanf("%d",&size);
    int arr[size];
    for(i=0 ; i<size ; i++){
        printf("Enter Element: ");
        scanf("%d",&arr[i]);
    }
    printf("Insert Element: ");
    scanf("%d",&n);
    

    for(i=0 ; i<size-1 ; i++){
        if(arr[i]>=n){
            arr[i] = arr[i+1];
        }
    }
    for(i=0 ; i<size-1 ; i++){
        printf("%d ",arr[i]);
    }

}
