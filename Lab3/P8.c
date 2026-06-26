#include <stdio.h>
#include <string.h>
int main(){

    int n , i , j;
    printf("Enter a size of an array  :");
    scanf("%d",&n);

    char arr[n][100];

    for(i=0 ; i<n ;i++){
        printf("Enter a String: ");
        scanf("%s" ,  arr[i]);
    }
    for(i=0 ; i<n-1 ;i++){
        for(j=i+1 ; j<n ; j++){

            if(strcmp(arr[i],arr[j])>0){

                char temp[100];
                strcpy(temp,arr[j]);
                strcpy(arr[j],arr[i]);
                strcpy(arr[i],temp);
            }
        }
    }
    for(i=0 ; i<n ;i++){
        printf("%s  " , arr[i]);
       
    }
}