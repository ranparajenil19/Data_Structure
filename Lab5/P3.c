#include <stdio.h>
#include <stdlib.h> 
#include<String.h>
#include <time.h>
int main(){
    int n;
    printf("Enter a Number of Word :");
    scanf("%d",&n);

    char arr[n][100];
    char s1[100];
    int random_num;

    for(int i=0 ; i<n ; i++){
        printf("Enter a Word : ");
        scanf("%s",arr[i]);
    }
    srand(time(NULL));

    random_num = rand() % (n);


    printf("Display Word: ");
    printf("\n");
    printf(" %s ",arr[random_num]);

    printf("\n");
    printf("Enter its Anagram : ");
    scanf("%s",s1);

    int freq1[26]={0};
    int freq2[26]={0};

    if(strlen(arr[random_num])!=strlen(s1)){
        printf("Not Anagram");

    }
    else{
        for(int i=0 ; arr[random_num][i]!='\0' ; i++){

            int temp = arr[random_num][i] - 'a';
            freq1[temp]++;
        }

        for(int i=0 ; s1[i]!='\0' ; i++){
            int temp2 = s1[i] - 'a';
            freq2[temp2]++;
        }

        for(int i=0 ; i<26 ; i++){
            if(freq1[i]!=freq2[i]){
                printf("Not Anagram  :");
                return 0;
            }
        }
        printf("It is Anagram");

    }


}
