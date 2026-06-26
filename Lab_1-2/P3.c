#include <stdio.h>
int main(){

    char ch;
    printf("Enter a small Character: ");
    scanf("%c",&ch);

    if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
        printf("Charcter is Vowel");
    }
    else{
        printf("Not Vowel");
    }
}