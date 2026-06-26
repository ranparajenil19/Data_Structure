#include <stdio.h>
#include <math.h>
int main()
{

    int  rem, count = 0, i, temp;
    double sum = 0;

    for (i = 1; i <= 1000; i++)
    {
        temp = i;
        sum = 0;
        count = 0;

        while (temp != 0)
        {
            count++;
            temp = temp / 10;
        }
        temp = i;
        while (temp != 0)
        {

            rem = temp % 10;
            sum = sum + pow((float)rem, count);

            temp = temp / 10;
        }
        if(sum==i){
            printf(" %d " , i);
        }
    }
}