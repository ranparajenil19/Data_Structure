#include <stdio.h>
#include <String.h>
#include <stdlib.h>

int main(){
   
    char *s = (char*)malloc(50*(sizeof(char)));
    char *rev_s = (char*)malloc(50*(sizeof(char)));

    printf("Enter a String :  ");
    scanf(" %[^\n]",s);

    strcpy(rev_s,s);
    strrev(rev_s);

    if((strcmp(s,rev_s)==0)){
        printf("Palindrome");

    }
    else{
        printf("Not Palindrome");
    }

}
