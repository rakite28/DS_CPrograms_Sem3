
#include<stdio.h>
#include<conio.h>
#include<time.h>

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
    int i,a[100000],n,l,r;
    clock_t start_t, end_t;
    double total_t;
    srand(time(0));
    FILE *fpt;
    fpt = fopen("QuickSortTC.csv", "w+");
    fprintf(fpt,"n,time_taken\n");
for(n=1;n<=100000;n++)
{   
    for(int i=0;i<n;i++)
    {
        a[i]=(float)rand();
    }
    start_t = clock();
    l=0;
    r=n-1;
    quickSort(a,l,r);
    // for(i=0;i<n;i++)
    // {
    //     printf("%d\n",a[i]);
    // }
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );

   fprintf(fpt,"%d, %f\n",n,total_t);
}
fclose(fpt);
}