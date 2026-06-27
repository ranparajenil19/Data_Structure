#include <stdio.h>
#include<stdlib.h>
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

    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(*(arr+i)>=*(arr+j)){
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
    printf("----------------PRINTING--------------");
    printf("\n");

    for(int i=0 ; i<n ; i++){
        printf(" %d ",*(arr+i));
    }

    free(arr);
    arr = NULL;
}