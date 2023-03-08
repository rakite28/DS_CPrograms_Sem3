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

struct node * create_ll(struct node *);
struct node * display(struct node *);
struct node * insert_beg(struct node *);
struct node * insert_end(struct node *);
struct node * insert_bef(struct node *);
struct node * insert_after(struct node *);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * delete_after(struct node *);
struct node * delete_node(struct node *);
struct node * delete_ll(struct node *);
struct node * sort(struct node *);

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num!=-1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start == NULL)
        {
            new_node -> next = new_node;
            start = new_node;
        }
        else
        { 
            ptr = start;
            while(ptr -> next != start)
            ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> next = start;
        }
    printf("\n Enter the data : ");
    scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr -> next != start)
    {
        printf("\n %d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n %d\n", ptr -> data);
    return start;
}

struct node *insert_beg(struct node *)
{
    struct node *nn,*ptr=start;
    int data;
    printf("Enter the data");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
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
    nn->next=start;
    ptr=start;
    while(ptr->next!=start)
    {
    ptr=ptr->next;
    }
    ptr->next=nn;
    return start;
}

struct node *insert_before(struct node *)
{
    struct node *nn,*ptr,*pp;
    int val,data;
    printf("Enter value before which");
    scanf("%d",&val);
    printf("Enter vallue to be entered");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    ptr=start;
    pp=start;
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
    printf("Enter value after which");
    scanf("%d",&val);
    printf("ENter vallue to be entered");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    pp=start;
    ptr=start->next;
    while(pp->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=nn;
    nn->next=ptr;
    return start;
}


struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
    ptr = ptr -> next;
    ptr -> next = start -> next;
    free(start);
    start = ptr -> next;
    return start;
}

struct node *delete_end(struct node *)
{
    struct node *ptr,*pp;
    ptr=start;
    while(ptr->next!=start)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=start;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *)
{
    struct node *ptr,*pp;
    ptr=start;
    pp=start;
    int val;
    printf("Enter value after to delete");
    scanf("%d",&val);
    while(pp->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    free(ptr);
    return start;
}

struct node *delete_before(struct node*)
{
    struct node *pp,*ptr,*pop;
    int val;
    printf("Enter value before to delete");
    scanf("%d",&val);
    pp=start;
    ptr=start;
    pop=ptr->next;
    if(start->data==val)
    {
        return start;
    }
    while(pop->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
        pop=ptr->next;
    }
    pp->next=pop;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *)
{
    struct node *ptr,*pp;
    ptr=start;
    pp=start;
    int val;
    printf("Enter value after to delete");
    scanf("%d",&val);
    while(ptr->data!=val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
    start = delete_end(start);
    free(start);
    return start;
}

struct node *sort_list(struct node *)
{
    int t;
    struct node *ptr1,*ptr2;
    ptr1=start;

    while(ptr1->next!=start)
    {
        ptr2=ptr1->next;
        while(ptr2!=start)
        {
            if(ptr1->data>ptr2->data)
            {
                t=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=t;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;
}

void main()
{
    int ch,x;
    do
    {
        printf(" 1=create ll\n 2=display\n 3=insert beg\n 4=insert end\n 5=insert bef\n 6=insert after\n 7=delete beg\n 8=delete end\n 9=delete after\n 10=delete before\n11=delete node\n 12=delete ll\n 13=sort\n 14=exit\n");
	    scanf("%d",&ch);
	    switch(ch){
	    case 1: start=create_ll(start);
	        break;
	    case 2: start=display(start);
	    	break;
	    case 3: start=insert_beg(start);
    	    break;
	    case 4: start=insert_end(start);
	        break;
	    case 5: start=insert_before(start);
	        break;
	    case 6: start=insert_after(start);
    	    break;
	    case 7: start=delete_beg(start);
    	    break;
	    case 8: start=delete_end(start);
	        break;
	    case 9: start=delete_after(start);
	        break;
        case 10:start=delete_before(start);
            break;
	    case 11: start=delete_node(start);
	        break;
	    case 12: start=delete_list(start);
	        break;
	    case 13: start=sort_list(start);
    	    break;
	    }
	}while(ch!=14);
    
}

/*
struct node *delete_after(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr -> data != val)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
if(ptr == start)
start = preptr -> next;
free(ptr);
return start;
}
struct node *delete_list(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr -> next != start)
start = delete_end(start);
free(start);
return start;
}
*/


