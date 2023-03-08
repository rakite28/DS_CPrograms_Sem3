#include <stdio.h>
int exp_rec(int, int);
void main()
{
    int num1, num2, res;
    printf("\n Enter the two numbers: ");
    scanf("%d %d", &num1, &num2);
    res = exp_rec(num1, num2);
    printf ("\n RESULT = %d", res);
}

int exp_rec(int x, int y)
{
    if(y==0)
        return 1;
    else
        return (x * exp_rec(x, y-1));
}