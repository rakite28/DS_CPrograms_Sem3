#include<stdio.h>
#include<conio.h>
void main()
{
    int a[20],b[30],i,j,k,count,n;
    printf("Enter frame size:");
    scanf("%d",&n);
    printf("Enter the frame in form of 0 and 1");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //if want a continuous string of integer use gets ptherwise put space between 0s and 1s
    i=0;
    count=1;
    j=0;
    while(i<n)
    {
        if(a[i]==1)
        {
            b[j]=a[i];
            for(k=i+1;a[k]==1 && k<n && count<5;k++)
            {
                j++;
                b[j]=a[k];
                count++;
                if(count==5)
                {
                    j++;
                    b[j]=0;
                    count=0;
                }
                i=k;
            }
        }
        else
        {
            b[j]=a[i];
        }
        i++;
        j++;
    }
    printf("After bit stuffing");
    for(i=0;i<j;i++)
    {
        printf("%d",b[i]);
    }
}