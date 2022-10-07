
#include<stdio.h>
#include<conio.h>

void quickSort(int number[25],int first , int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
            i++;
            while(number[j]>number[pivot])
            j--;
            if(i<j)
            {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quickSort(number,first,j-1);
        quickSort(number,j+1,last);
    }
}

void main()
{
    int i,a[100],n,l,r;
    printf("Enter a no.");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %d element",i+1);
        scanf("%d",&a[i]);
    }
    l=0;
    r=n-1;
    quickSort(a,l,r);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}