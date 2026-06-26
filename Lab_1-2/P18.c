#include <stdio.h>
int main(){
    int n1,n2,i,j;
    printf("Enter a value of N1: ");
    scanf("%d",&n1);
    printf("Enter a value of N2: ");
    scanf("%d",&n2);

    for(i=n1 ; i<=n2 ;i++){
        int count=0;
        for(j=2 ; j<i ; j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==0){
            printf("%d ",i);
        }
    }
}