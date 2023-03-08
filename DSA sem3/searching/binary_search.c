#include<stdio.h>
#include<conio.h>

int Binarysearch(int a[],int n, int x)
{
    int l=0,h=n-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==x)
        return m;
        else if(a[m]<x)
        l=m+1;
        else
        h=m-1;
    }
    return -1;
}
void BubbleSort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1]) //ascending order
            //if(a[j]<a[j+1])//descending order
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
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

    BubbleSort(a,n);

    i=Binarysearch(a,n,x);
    if(i==-1)
    {
        printf("Number not found");
    }
    else
    {
        printf("Number found at %d index",i);
    }
}