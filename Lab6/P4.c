#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Enter size of an Array: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
   
    printf("---------------VALUES-----------");
    printf("\n");
    for(int i=0 ; i<n ; i++){
        printf("Enter a Element: ");
        scanf("%d",(arr+i));
    }
   
    int *pmax = arr;

    for(int i=1 ; i<n ; i++){
        if(*(arr+i)>=*pmax){
            *pmax = *(arr+i);
        }
    }
    printf("\n");
    printf("Maximum Number: %d",*pmax);

    free(arr);
    
    arr=NULL;
    pmax=NULL;
}