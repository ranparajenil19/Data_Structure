#include <stdio.h>
int main(){

    int b , p;
    printf("Enter a Base :");
    scanf("%d",&b);

    printf("Enter a Power : ");
    scanf("%d",&p);
    int ans=1 , i=1,j=1;
    int temp = b;

    for(i=1 ; i<p ; i++){
        ans=0;
        for(j=1 ; j<=b ;j++){
            ans+=temp;
        }
        temp =ans;
    }
    printf("Value is : %d",ans);
}