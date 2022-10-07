#include<stdio.h>
#include<conio.h>

void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c \n",n,from_rod,to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void main()
{
    int N=3;
    printf("Enter no of pegs");
    scanf("%d",&N);
    towerOfHanoi(N, 'A', 'C', 'B');
}

