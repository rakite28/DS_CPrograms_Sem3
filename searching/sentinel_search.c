#include<stdio.h>
#include<conio.h>

void SentinelSearch(int a[], int n, int x)
{
    int last=a[n-1];
    a[n-1]=x;
    int i=0;
    while(a[i]!=x)
    i++;
    a[n-1]=last;
    if(i<n-1 || a[n-1]==x)
    printf("Found at %d index",i);
    else
    printf("Not Found");
}

void main()
{
    int i,n,a[100],x;
    printf("Enter a no.");
    scanf("%d",&n);
    printf("Enter a array\n");
    for(i=0;i<n;i++)
    {
        printf("Enter %d element",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched");
    scanf("%d",&x);

    SentinelSearch(a,n,x);
}