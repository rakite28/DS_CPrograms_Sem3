#include<stdio.h>
#include<conio.h>

int LinearSearch(int a[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;

}

void main()
{
    int i,n,a[100],x;
    printf("Ente a no.");
    scanf("%d",&n);
    printf("Enter a array\n");
    for(i=0;i<n;i++)
    {
        printf("Enter %d element",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched");
    scanf("%d",&x);

    i=LinearSearch(a,n,x);
    if(i==-1)
    {
        printf("Number not found");
    }
    else
    {
        printf("Number found at %d index",i);
    }
}