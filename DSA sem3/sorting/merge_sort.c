#include<stdio.h>
#include<conio.h>

void merge(int arr[],int l,int m, int r);

void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void merge(int arr[],int l,int m, int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;

    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n1)
    {
        arr[k]=R[j];
        j++;
        k++;
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
    mergeSort(a,l,r);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }


}