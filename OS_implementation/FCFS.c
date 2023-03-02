// C program for implementation of FCFS 
// scheduling
#include<stdio.h>
// Function to find the waiting time for all 
// processes
void findWaitingTime(int processes[], int n, int bt[], int wt[],int at[])
{
    // waiting time for first process is 0
    wt[0] = at[0];
    // calculating waiting time
    for (int i = 1; i < n ; i++ )
    {
        wt[i] =  bt[i-1] + wt[i-1];
        if( wt[i] <at[i])
        {
            wt[i]=at[i];
        }
    }
}
   
// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, 
                  int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
   
//Function to calculate average time
void findavgTime( int processes[], int n, int bt[],int at[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
   
    //Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt,at);
   
    //Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
   
    //Display processes along with all details
    printf("Processes   Arrival Time   Burst time   Waiting time   Turn around time\n");
   
    // Calculate total waiting time and total turn 
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("        %d\t",at[i]);
        printf("        %d\t ", bt[i] );
        printf("        %d\t",wt[i] );
        printf("        %d\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
}
   
// Driver code
int main()
{
    int temp=0;
    //process id's
    int processes[] = { 1, 2, 3};
    int at[]={0,11,2};
    int  burst_time[] = {10, 5, 8};
    int n = sizeof processes / sizeof processes[0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=burst_time[j];
                burst_time[j]=burst_time[j+1];
                burst_time[j+1]=temp;

            }
        }
    }
   
    //Burst time of all processes
    
   
    findavgTime(processes, n,  burst_time,at);
    return 0;
}
