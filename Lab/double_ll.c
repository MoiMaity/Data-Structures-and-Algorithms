#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

struct node *newNode()
{
	struct node *temp=malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void insert_begin()
{
	struct node *temp= newNode();
	if (head==NULL)
	{
		head=temp;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;	
	}
}

void insert_last()
{
	struct node *temp= newNode();
	struct node *ptr=head;
	if (head==NULL)
	{
		head=temp;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	}
}

void display()
{
	printf("\nList: ");
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("\nList is empty");
	}
	else{
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
	}
}

void main()
{
	int n;
	printf("\n....DOUBLE LINK LIST....\n");
	while(1)
	{
	printf("\n\n 1.Insert node at begin. \n 2.Insert node at end. \n 3.EXIT");
	display();
	printf("\nEnter Your choice: ");
	scanf("%d",&n);
	switch(n)
	{
		case 1: insert_begin();
				break;
		case 2: insert_last(); 
				break;
		case 3: exit(0);
		default: printf("\nincorrect Choice");		
	}	
	}
}
