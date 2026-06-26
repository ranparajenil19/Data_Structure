#include <stdio.h>
int main(){

    int i,size,p;

    printf("Enter a size of an array:");
    scanf("%d",&size);

    int arr[size-1];
    for(i=0 ; i<size ; i++){
        printf("Enter a Element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter a Position From you want to delete Element : ");
    scanf("%d",&p);

    for(i=p ; i<size ; i++){
        arr[i-1] = arr[i];
    }
    for(i=0 ; i<size-1 ; i++){
        printf("%d ",arr[i]);
    }

}