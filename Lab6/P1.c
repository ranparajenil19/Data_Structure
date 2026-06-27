#include <stdio.h>
#include<stdlib.h>
int main(){

    int *pi = NULL;
    float *pf = NULL;
    char *pc = NULL;

    pi = (int*)malloc(sizeof(int));
    pf = (float*)malloc(sizeof(float));
    pc = (char*)malloc(sizeof(char));

    if(pi==NULL || pc==NULL || pf==NULL){
        printf("Adderess is not Given:");
        return 0;
    }

    printf("---------------VALUES--------------");
    printf("\n");
    printf("Enter a Value in int: ");
    scanf("%d",pi);
    printf("Enter value in Float:  ");
    scanf("%f",pf);
    printf("Enter a value in Char: ");
    scanf(" %c",pc);

     printf("\n");

    printf("------------Print-------------");
     printf("\n");
    printf("Int Value: %d",*pi);
     printf("\n");
    printf("Float Value: %.2f",*pf);
     printf("\n");
    printf("Char Value: %c",*pc);
     printf("\n");
    
    free(pi);
    free(pf);
    free(pc);

   pi = NULL;
    pf = NULL;
    pc = NULL;

}