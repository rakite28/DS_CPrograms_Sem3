#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20

int st[MAX],top=-1;

void push(int x)
{
    if(top==MAX-1)
    printf("stack overflow\n");
    else
    st[++top]=x;
}

int pop()
{
    if(top==-1)
    printf("stack underflow\n");
    else
    return st[top--];
}

void main()
{
    char exp[MAX],temp;
    int i,flag=1;
    printf("Enter the expression\n");
    gets(exp);
    for(i=0;i<strlen(exp);i++)
    { 
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
	        push(exp[i]);
        }
        if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
	        if(top==-1)
	        {
                flag=0;
            }
	        else
	        {	
                temp=pop();
		        if(exp[i]==')' && (temp=='['||temp=='{'))
                flag=0;
		        if(exp[i]=='}' && (temp=='('||temp=='['))
		        flag=0;
		        if(exp[i]==']' && (temp=='('||temp=='{'))
		        flag=0;
	        }
            
        }
    }
    if(top>=0)
    flag=0;
    if(flag==1)
    printf("valid expression\n");
    else
    printf("invalid expression\n");
}