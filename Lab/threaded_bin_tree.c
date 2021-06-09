#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define infinity 9999

typedef enum {thread,link} boolean;
struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);

struct node
{
    struct node *left_ptr;
    boolean left;
    int info;
    boolean right;
    struct node *right_ptr;
}*head=NULL;

void main()
{
    int choice,num;
    insert_head();
    while(1)
    {
        printf("\n");
        printf("1.Insert\n");
        printf("2.Inorder Traversal\n");
        printf("3.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
         	case 1:
            	printf("Enter the number to be inserted : ");
            	scanf("%d",&num);
            	insert(num);
            	break;
         	case 2:
            	inorder();
            	break;
        	case 3:
        		exit(1);
         	default:
            	printf("Wrong choice\n");
        }
    }
	getch();
}

int insert_head()
{
    struct node *tmp;
    head=(struct node *)malloc(sizeof(struct node));
    head->info= infinity;
    head->left=thread;
    head->left_ptr=head;
    head->right=link;
    head->right_ptr=head;
}

int find(int item,struct node **par,struct node **loc)
{
    struct node *ptr,*ptrsave;
    if(head->left_ptr==head)  
    {
        *loc=NULL;
        *par=head;
        return;
    }
    if(item==head->left_ptr->info) 
    {
        *loc=head->left_ptr;
        *par=head;
        return;
    }
    ptr=head->left_ptr;
    while(ptr!=head)
    {
        ptrsave=ptr;
        if( item < ptr->info )
        {
            if(ptr->left==link)
                ptr=ptr->left_ptr;
            else
                break;
        }
        else
            if(item > ptr->info )
            {
            	if(ptr->right==link)
                ptr=ptr->right_ptr;
            else
                break;
            }
        if(item==ptr->info)
        {
            *loc=ptr;
            *par=ptrsave;
            return;
        }
    }
    *loc=NULL; 
    *par=ptrsave;
}

int insert(int item)
{
    struct node *tmp,*parent,*location;
    find(item,&parent,&location);
    if(location!=NULL)
    {
        printf("Item already present");
        return;
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=item;
    tmp->left=thread;
    tmp->right=thread;
    if(parent==head)
    {
        head->left=link;
        head->left_ptr=tmp;
        tmp->left_ptr=head;
        tmp->right_ptr=head;
    }
    else
        if( item < parent->info )
        {
            tmp->left_ptr=parent->left_ptr;
            tmp->right_ptr=parent;
            parent->left=link;
            parent->left_ptr=tmp;
        }
        else
        {
            tmp->left_ptr=parent;
            tmp->right_ptr=parent->right_ptr;
            parent->right=link;
            parent->right_ptr=tmp;
        }
}

struct node *in_succ(struct node *ptr)
{
    struct node *succ;
    if(ptr->right==thread)
        succ=ptr->right_ptr;
    else
    {
        ptr=ptr->right_ptr;
        while(ptr->left==link)
            ptr=ptr->left_ptr;
        succ=ptr;
    }
    return succ;
}

struct node *in_pred(struct node *ptr)
{
    struct node *pred;
    if(ptr->left==thread)
        pred=ptr->left_ptr;
    else
    {
        ptr=ptr->left_ptr;
        while(ptr->right==link)
            ptr=ptr->right_ptr;
        pred=ptr;
    }
    return pred;
}

void inorder()
{
    struct node *ptr;
    if(head->left_ptr==head)
    {
        printf("Tree is empty");
        return;
    }
    ptr=head->left_ptr;
    while(ptr->left==link)
        ptr=ptr->left_ptr;
    printf(" %d ",ptr->info);
    while(1)
    {
        ptr=in_succ(ptr);
        if(ptr==head)     
            break;
        printf(" %d  ",ptr->info);
    } 
}
