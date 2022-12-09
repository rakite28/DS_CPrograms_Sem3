#include <stdio.h>
#include<stdlib.h>
#define size 10

int h[size];
void insert();
void search();
void display();

int main()
{
    int option;
    for (int j = 0; j < size; j++)
    {
        h[j] = -1;
    }
    do
    {
        printf("\n MAIN MENU");
        printf("\n 1. INSERT");
        printf("\n 2. SEARCH");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf( "%d", &option);
        switch(option)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                search();
                break;
            }
            case 3:
            {
                display();
                break;
            }
        }
    }while(option!=4);
    return 0;
}


void insert()
{
    int key,index,i,hkey;
    printf("\n Enter a value to insert into hash table\n");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0;i<size;i++)
    {
        index=(hkey+i)%size;
        if(h[index] == -1)
        {
            h[index]=key;
            break;
        }
    }
    if(i == size)
    {
        printf("\n Element cannot be inserted\n");
    }
}

void search()
{
    int key,index,i,flag=0,hkey;
    printf("\n Enter search element\n");
    scanf("%d",&key);
    hkey=key%size;
    for(i=0;i<size; i++)
    {
        index=(hkey+i)%size;
        if(h[index]==key)
        {
            printf(" Value is found at index %d",index);
            break;
        }
    }
    if(i == size)
    {
        printf("\n Value is not found\n");
    }
}

void display()
{
    int i;
    printf("\n Elements in the hash table are \n");
    for(i=0;i< size; i++)
    {
        printf("\n At index %d \t value =  %d",i,h[i]);
    }
}