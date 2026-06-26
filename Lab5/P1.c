#include <stdio.h>
int main(){

    int arr1[3][2];
    int arr2[2][3];
    int arr3[3][3];

    printf("First Array Element:");
    printf("\n");
    for(int i=0 ; i<3 ;i++){
        for(int j=0 ; j<2 ; j++){
            printf("Enter a Element:");
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("2nd Array: ");
    printf("\n");
     for(int i=0 ; i<2 ;i++){
        for(int j=0 ; j<3 ; j++){
            printf("Enter a Element:");
            scanf("%d",&arr2[i][j]);
        }
    }


    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){

            arr3[i][j] = arr1[i][0]*arr2[0][j] + arr1[i][1]*arr2[1][j];
        }
    }
    printf("Answer: ");
    printf("\n");
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            printf("  %d  ",arr3[i][j]);
        }

        printf("\n");
    }
}