#include<stdio.h>
#include<stdlib.h>
int main(){

    int n;
    printf("Enter a Size Of an Array: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    printf("--------------VALUES-------------");
    printf("\n");
    for(int i=0 ; i<n ; i++){
        printf("Enter a Element: ");
        scanf("%d",(arr+i));
    }
    printf("\n");

    printf("----------------PRINTING--------------");
    printf("\n");

    for(int i=0 ; i<n ; i++){
        printf(" %d ",*(arr+i));
    }

    free(arr);
    arr = NULL;
}