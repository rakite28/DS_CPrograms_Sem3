#include<stdio.h>
#include<conio.h>

void Selection_Sort(int n,int a[])
{
    int i,j,Min,temp;
    
    for(i=0;i<=n-2;i++)
    {
        Min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[Min])
            {
            Min=j;
            }
        }
        temp=a[i];
        a[i]=a[Min];
        a[Min]=temp;
    }
    printf("Sorted Array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }

}

void main()
{
    int n,a[100];

    printf("Enter size of array");
    scanf("%d",&n);
    printf("Enter array of no.s");
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element",i+1);
        scanf("%d",&a[i]);
    }

    Selection_Sort(n,a);

    
}