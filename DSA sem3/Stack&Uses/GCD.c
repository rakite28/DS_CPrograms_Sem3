#include <stdio.h>
int GCD(int, int);
void main()
{
    int num1, num2, res;
    printf("\n Enter the two numbers: ");
    scanf("%d %d", &num1, &num2);
    res = GCD(num1, num2);
    printf("\n GCD of %d and %d = %d", num1, num2, res);
}

int GCD(int x, int y)
{
    int rem;
    rem = x%y;
    if(rem==0)
        return y;
    else
        return (GCD(y, rem));
}