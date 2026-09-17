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
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop()
{
    if (top < 0)
    {
        printf("Invalid\n");
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

void reverseAndSwap(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

void infixToPostfix(char infix[], char polish[])
{
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
            printf("Invalid\n");
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
                printf("Invalid\n");
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

    if (top != -1 || rank != 1)
    {
        printf("Invalid\n");
        polish[0] = '\0';
    }
}

void infixToPrefix(char infix[])
{
    char polish[n] = "";

    
    reverseAndSwap(infix);


    infixToPostfix(infix, polish);

    if (strlen(polish) > 0)
    {
       
        reverseAndSwap(polish);
        printf("Prefix : %s\n", polish);
    }
}

int main()
{
    char infix[n];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPrefix(infix);

    return 0;
}