#include <stdio.h>
int main(){

    int day;
    int year=0 , week=0;
    printf("Enter a day:");
    scanf("%d",&day);

    while(day>=365){
       year++;
       day = day-365;
    }
    while(day>=7){
        week++;
        day = day-7;
    }
    printf("%d : %d : %d",year,week,day);


}