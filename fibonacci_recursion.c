#include <stdio.h>
int Fibonacci(int);
void main()
{
    int n, i = 0, res;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    printf("Fibonacci series\n");
    for(i = 0; i < n; i++ )
    {
        res = Fibonacci(i);
        printf("%d\t",res);
    }
}

int Fibonacci(int n)
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return ( Fibonacci(n-1) + Fibonacci(n-2));
}