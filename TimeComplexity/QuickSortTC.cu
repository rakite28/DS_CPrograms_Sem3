
#include<stdio.h>

#include<time.h>


__global__
void quickSort(int *a ,int first , int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot]&&i<last)
            i++;
            while(a[j]>a[pivot])
            j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quickSort<<<1,1>>>(a,first,j-1);
        quickSort<<<1,1>>>(a,j+1,last);
    }
}

int main(void)
{
    int i,*a,n,l,r;
    n=1<<10;
    cudaMallocManaged(&a,n*sizeof(int));
    clock_t start_t, end_t;
    double total_t;
    srand(time(0));
    FILE *fpt;
    fpt = fopen("QuickSortTC.csv", "w+");
    fprintf(fpt,"n,time_taken\n");
for(i=1;i<=n;i++)
{   
    for(int j=0;j<n;j++)
    {
        a[j]=(float)rand();
    }
    start_t = clock();
    l=0;
    r=n-1;
    quickSort<<<1,1>>>(a,l,r);
    cudaDeviceSynchronize();
    // for(i=0;i<n;i++)
    // {
    //     printf("%d\n",a[i]);
    // }
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );
    

   fprintf(fpt,"%d, %f\n",i,total_t);
}
cudaFree(a);
fclose(fpt);
return 0;
}