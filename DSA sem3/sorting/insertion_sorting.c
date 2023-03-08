#include<stdio.h>
#include<conio.h>

void InsertionSort(int a[],int n)
{
    int j,temp;
    for(int i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp )
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

void main()
{
    int i,n,a[100];
    printf("Enter a no.");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Ente %d element",i+1);
        scanf("%d",&a[i]);
    }

    InsertionSort(a,n);

    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
