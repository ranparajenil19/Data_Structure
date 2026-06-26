#include <stdio.h>
int main(){

    int n,i;
    float sum, avg;

    
    printf("Enter a size of an array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0 ; i<n ;i++){
        arr[i] = i+1;
        sum+=arr[i];
    }
    avg = sum/n;
    printf("Average of All Element : %.2f ",avg);
}