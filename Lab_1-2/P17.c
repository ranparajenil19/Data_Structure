#include <stdio.h>
int main(){
    int n;
    printf("Enter a Number :");
    scanf("%d",&n);

    int i;
    for(i=1 ; i<=n ; i++){
        if(n%i==0){
            printf("%d  ",i);
        }
    }
}