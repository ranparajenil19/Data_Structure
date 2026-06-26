#include <stdio.h>
int main(){

    int n , i , j;
    printf("Enter a size of an array  :");
    scanf("%d",&n);

    int arr[n][n];

    for(i=0 ; i<n ;i++){
        for (int space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for(j=0 ; j<=i ; j++){
            if(j==0 || j==i){
                arr[i][j] = 1;
                printf("%d " , arr[i][j]);
            }
            else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                printf("%d " , arr[i][j]);
            }
           
        }
         printf("\n");
    }
}