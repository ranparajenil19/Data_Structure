#include <stdio.h>

struct student
{
   int roll_no;
   char name[50];
   char branch[50];
   int branch_no;
};

int main(){
    struct student s1;
    struct student *ptr = &s1;

    printf("Enter Roll No: ");
    scanf("%d",&ptr->roll_no);

    printf("Enter Name :");
    scanf(" %[^\n]",ptr->name);

    printf("Enter Branch: ");
    scanf(" %[^\n]",ptr->branch);

    printf("Enter Branch No: ");
    scanf("%d",&ptr->branch_no);

    printf("%d",ptr->roll_no);
    printf("\n");
    printf("%[^\n]",ptr->name);
    printf("\n");
    printf("%[^\n]",ptr->branch);
    printf("\n");
    printf("%d",ptr->branch_no);

}