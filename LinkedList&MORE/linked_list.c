#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start =NULL;

struct node *create_ll(struct node *)
{
    struct node *nn,*ptr;
    int data;
    printf("Enter -1 to stop");
    printf("enter value");
    scanf("%d",&data);
    while(data!=-1)
    {
        nn=(struct node *)malloc(sizeof(struct node));
        nn->data=data;
        nn->next=NULL;
        if(start==NULL)
        start=nn;
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
                ptr->next=nn;
            }
        }
        printf("Enter a no.");
        scanf("%d",&data);
    }
    return start;  
}

struct node *display(struct node *)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

struct node *insert_beg(struct node *)
{
    struct node *nn;
    int data;
    printf("Enter the data");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=start;
    start=nn;
    return start;
}

struct node *insert_end(struct node *)
{
    struct node *nn,*ptr;
    int val;
    printf("Enter value");
    scanf("%d",&val);

    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=nn;
    return start;
}

struct node *insert_before(struct node *)
{
    struct node *nn,*ptr,*pp;
    int val,data;
    printf("Enter value before which");
    scanf("%d",&val);
    printf("ENter vallue to be entered");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    ptr=start;
    while(ptr->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=nn;
    nn->next=ptr;
    return start;
}

struct node *insert_after(struct node *)
{
    struct node *nn,*ptr,*pp;
    int val,data;
    printf("Enter value before which");
    scanf("%d",&val);
    printf("ENter vallue to be entered");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    pp=start;
    ptr=start;
    while(pp->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=nn;
    nn->next=ptr;
    return start;
}



// struct node *delete_beg(struct node *)
// {

// }

// struct node *delete_after(struct node *)
// {

// }

// struct node *delete_node(struct node *)
// {

// }

// struct node *delete_list(struct node *)
// {

// }

// struct node *sort_list(struct node *)
// {

// }

void main()
{
    int ch,x;
    do
    {
        printf("Enter \n1->create ll\n2->display\n..");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            start=create_ll(start);
            break;
            case 2:
            start=display(start);
            break;
            case 3:
            start=insert_beg(start);
            break;
            case 4:
            start=insert_end(start);
            break;
            case 5:
            start=insert_before(start);
            break;
            case 6:
            start=insert_after(start);
            break;
            // case 7:
            // start=delete_beg(start);
            // break;
            // case 8:
            // start=delete_end(start);
            // break;
            // case 9:
            // start=delete_before(start);
            // break;
            // case 10:
            // start=delete_after(start);
            // break;
            // case 11:
            // start=delete_node(start);
            // break;
            // case 12:
            // start=delete_list(start);
            // break;
            // case 13:
            // start=sort_list(start);
            // break;

        }
    } while (ch!=13);
    
}




