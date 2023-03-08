#include <stdio.h>
#include <conio.h>
int stk[10];
int top=-1;
int pop();
void push(int);

void main()
{
    int val, n, i,arr[10];
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    for(i=0;i<n;i++)
        push(arr[i]);
    for(i=0;i<n;i++)
    {
        val = pop();
        arr[i] = val;
    }
    printf("\n The reversed array is : ");
    for(i=0;i<n;i++)
        printf("\n %d", arr[i]);
}
void push(int val)
{
    stk[++top] = val;
}
int pop()
{
    return(stk[top--]);
}