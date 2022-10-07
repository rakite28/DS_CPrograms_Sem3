#include<stdio.h>
#include<conio.h>

void BubbleSort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            // if(a[j]>a[j+1]) ascending order
            if(a[j]<a[j+1])//descending order
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
    int a[100],i,j,t,n;
    printf("Enter a no.");
    scanf("%d",&n);

    printf("Enter array");
    for(i=0;i<n;i++)
    {
        printf("enter %d element",i+1);
        scanf("%d",&a[i]);
    }

    BubbleSort(a,n);

    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}