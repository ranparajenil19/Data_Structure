#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter a Three Number:");
    scanf("%d %d %d",&a,&b,&c);

    if(a>b && a>c){
        printf("a is largest:" , a);
    }
    else{
        if(b>c){
            printf("b is largest:" , b);
        }
        else{
            printf("C is largest" , c);
        }
    }
}