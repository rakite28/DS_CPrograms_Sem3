#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>

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
    

}

void main()
{
    int n,a[10000];
    clock_t start_t, end_t;
    double total_t;
    int rand(void);
    srand(time(0));
    FILE *fpt;
    fpt = fopen("SelectionSortTC.csv", "w+");
    fprintf(fpt,"n,time_taken\n");
for(n=1;n<=10000;n++)
{   
    for(int i=0;i<n;i++)
    {
        a[i]=(float)rand();
    }
    start_t = clock();
    Selection_Sort(n,a);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );

   fprintf(fpt,"%d, %f\n",n,total_t);
}
fclose(fpt);

    

    
}