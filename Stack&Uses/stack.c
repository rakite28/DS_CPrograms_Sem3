#include<stdio.h>
#include<conio.h>
#define MAX 10

int st[MAX],top=-1;

void push(int x)
{
    if(top==MAX-1)
    printf("Stack Overflow");
    else
    st[++top]=x;
}

void pop()
{
    if(top==-1)
    printf("Stack Overflow");
    else
    printf("pop element is %d",st[top--]);
}

int peek()
{
    if(top==-1)
    return -1;
    else
    return st[top];
}

void display()
{
    int i;
    if(top==-1)
    printf("Stack is empty");
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("Elements are %d",st[i]);
        }
    }

}

void main()
{
    int ch,x;
    do
    {
        
        printf("\n1=push\n2=pop\n3=peek\n4=display\n5=exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter a no.");
            scanf("%d",&x);
            push(x);
            break;
            case 2: pop();
            break;
            case 3: x=peek();
            if(x==-1)
            printf("Stack Overflow");
            else
            printf("Peeked element is %d",x);
            break;
            case 4:
            display();
            break;
        }

    } while (ch!=5);
    
}