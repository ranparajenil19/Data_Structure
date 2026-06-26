#include <stdio.h>
int main(){

    int second;
    int hr=0 , min=0;
    printf("Enter a Second:");
    scanf("%d",&second);

    while(second>=3600){
       hr++;
       second = second-3600;
    }
    while(second>=60){
        min++;
        second = second-60;
    }
    printf("%d : %d : %d",hr,min,second);


}