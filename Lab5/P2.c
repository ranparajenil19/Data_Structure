#include <stdio.h>
int main(){

    int arr1[2][2];
    int arr2[2][2];
    int arr3[2][2];

     printf("First Array Element:");
    printf("\n");
    for(int i=0 ; i<2 ;i++){
        for(int j=0 ; j<2 ; j++){
            printf("Enter a Element:");
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n");

    printf("Second Array Element:");
    printf("\n");
    for(int i=0 ; i<2 ;i++){
        for(int j=0 ; j<2 ; j++){
            printf("Enter a Element:");
            scanf("%d",&arr2[i][j]);
        }
    }
     for(int i=0 ; i<2 ;i++){
        for(int j=0 ; j<2 ; j++){

            arr3[i][j] = arr1[i][j] + arr2[i][j];

        }
    }
     printf("Answer: ");
    printf("\n");
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            printf("  %d  ",arr3[i][j]);
        }

        printf("\n");
    }
}