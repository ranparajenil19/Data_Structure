#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define n 100
char stack[n];
int top = -1;

void push(char ch)
{
    if (top >= n - 1)
    {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = ch;
}
char pop()
{
    if (top < 0)
    {
        printf("Invalid");
        return '\0';
    }
    return stack[top--];
}
int F(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 3;
    if (ch == '^')
        return 6;
    if (isalpha(ch) || isdigit(ch))
        return 7;
    if (ch == '(')
        return 9;
    if (ch == ')')
        return 0;
    return 0;
}

int G(char ch)
{
    if (ch == '+' || ch == '-')
        return 2;
    if (ch == '*' || ch == '/')
        return 4;
    if (ch == '^')
        return 5;
    if (isalpha(ch) || isdigit(ch))
        return 8;
    if (ch == '(')
        return 0;
    return 0;
}
int R(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return -1;
    if (isalpha(ch) || isdigit(ch))
        return 1;
    return 0;
}
void infixToPostfix(char infix[])
{
    char polish[n] = "";
    int polish_index = 0;
    int rank = 0;
    int i = 0;

    top = 0;
    stack[top] = '(';

    int len = strlen(infix);
    infix[len] = ')';
    infix[len + 1] = '\0';

    char next = infix[i++];

    while (next != '\0')
    {
        if (top < 0)
        {
            printf("Invalid");
            return;
        }
        while (G(stack[top]) > F(next))
        {
            char temp = pop();
            polish[polish_index++] = temp;
            polish[polish_index] = '\0';

            rank = rank + R(temp);

            if (rank < 1)
            {
                printf("Invalid");
                return;
            }
        }

        if (G(stack[top]) != F(next))
        {
            push(next);
        }
        else
        {
            pop();
        }

        next = infix[i++];
    }
    if(top!=-1 || rank!=1){
        printf("Invalid");
    }
    else{
        printf("Postfix : %s\n",polish);
    }
}
int main(){
    char infix[n];

    printf("Enter Infix Expresion : ");
    scanf("%s",infix);
    

    infixToPostfix(infix);

    return 0 ;
}
