#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100

float st[MAX];
int top=-1;

void push(float st[],float val)
{	
    if(top==MAX-1)
	printf("stack overflow\n");
	else
	st[++top]=val;
}

float pop(float st[])
{
    float val=-1;
    if(top == -1)
    printf("stack underflow\n");
    else
    { 
        val=st[top];
        top--;
    }
    return val;
}

float evaluatePostFixExp(char exp[])
{ 
    int i=0;
    float op1,op2,value;
    while(exp[i]!='\0')
    {	
        if(isdigit(exp[i]))
	        push(st, (float)(exp[i]-'0'));
	    else
        {
		    op2=pop(st);
		    op1=pop(st);
		    switch(exp[i])
            {
			    case '+': value= op1 + op2;
				break;
			    case '-': value= op1 - op2;
				break;
			    case '/': value= op1 / op2;
			    break;
			    case '*': value= op1 * op2;
				break;
			    case '%': value= (int)op1 % (int)op2;
				break;
		    }
		push(st,value);
	    }
	    i++;
    }
    return (pop(st));
}

void main()
{
    float val;
    char exp[100];
    printf("enter any postfix expression\n");
    gets(exp);
    val=evaluatePostFixExp(exp);
    printf("value of the postfix expressio is: %.2f\n",val);
}