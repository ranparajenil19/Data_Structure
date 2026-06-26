#include <stdio.h>
int main(){

    int i,n,size;
    printf("Enter a size of an array: ");
    scanf("%d",&size);

    int arr[size+1];
    for(i=0 ; i<size ; i++){
        printf("Enter a Element: ");
        scanf("%d",&arr[i]);

    }
    printf("Enter a element you want to add:");
    scanf("%d",&n);

    i = size-1;
    while (i >= 0 && arr[i] > n) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = n;
    for(i=0 ; i<size+1 ; i++){
        printf("%d ",arr[i]);
    }
}