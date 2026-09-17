#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverseStack() {
    int left = 0, right = top;
    while (left < right) {
        char temp = stack[left];
        stack[left] = stack[right];
        stack[right] = temp;
        left++;
        right--;
    }
}

void vowelAnxiety(char s[]) {
    top = -1; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (isVowel(s[i])) {
            reverseStack(); 
        }
        push(s[i]); 
    }

    
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main() {
    int t;
    printf("Enter number of test cases: ");
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        char str[MAX];
        scanf("%d", &n);
        scanf("%s", str);

        vowelAnxiety(str);
    }

    return 0;
}