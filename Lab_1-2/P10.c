#include<stdio.h>
#include<math.h>

int main(){

    int n , rem , count=0 ;
    double sum=0;
    printf("Enter a Number:");
    scanf("%d",&n);

    int temp = n;
    

    while(temp!=0){
        count++;
        temp = temp/10;

    }
    
    temp=n;
    while(temp!=0){

        rem = temp%10;
        sum = sum + pow((float)rem , count);

        temp = temp/10;

    }
    
    if((int)sum==n){
        printf("Number is Armstrong");
    }
    else{
        printf("Number is not Armstromg");
    }

}