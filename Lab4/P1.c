#include <stdio.h>
int main(){

    int n , p ,i , size;
    printf("Enter a size of an array:");
    scanf("%d",&size);

    int arr[size+1];
    for(i=0 ; i<size ; i++){
        printf("Enter a Element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter a new Element and it's Position: ");
    scanf("%d %d",&n,&p);

    for(i=size ; i>=p ; i--){
        arr[i] = arr[i-1];
    }
    arr[p-1] = n;

    for(i=0 ; i<size+1 ; i++){
        printf("%d ",arr[i]);
    }
}