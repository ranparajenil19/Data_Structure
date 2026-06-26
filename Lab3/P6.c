#include <stdio.h>
int main(){

    int n,i,first_number,second_number , index , count=0;

    printf("Enter a size of an array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0 ; i<n ;i++){
        printf("Enter element : ");
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Now Give Numbers : ");
    scanf("%d %d",&first_number,&second_number);

    for(i=0 ; i<n ;i++){
        if(arr[i]==first_number){
            count++;
            arr[i] = second_number;
            index = i;
        }
    }
    if(count==0){
        printf("No Number Avaliable To Replace");
    }
    else{
        printf("Index = %d" , index);
        printf("\n");
        for(i=0 ; i<n ; i++){
            printf("%d " , arr[i]);
        }
    }

}