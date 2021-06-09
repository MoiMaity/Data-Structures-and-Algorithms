#include<stdio.h>
#include<conio.h>
#include<process.h>
struct node
{
	int data;
	struct node *link;
}node;
struct node *header=NULL;
void create()
{
	printf("..Creating a node..");
	header=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter a value:");
	scanf("%d",&header->data);
	header->link=NULL;
}
void count()
{
	int c=0;
	struct node *ptr;
	printf("..counting nodes..");
	ptr=header;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->link;
	}
	printf("\nNo of nodes:%d",c);
	getch();
}
void display()
{
	struct node *ptr;
	ptr=header;
	while(ptr)
	{
		printf(" %d",ptr->data);
		ptr=ptr->link;
	}
}
void insert_beg()
{
	struct node *new,*ptr;
	if(header==NULL)
	{
		printf("Create node first");
		exit(1);
	}
	else
	{
		ptr=header;
		new=(struct node *)malloc(sizeof(struct node));
		printf("Enter new data:");
		scanf("%d",&new->data);
		new->link=ptr;
		header=new;
	}
}
void insert_end()
{
	struct node *new,*ptr;
	if(header==NULL)
	{
		printf("Create node first");
		exit(1);
	}
	else
	{
		ptr=header;
		new=(struct node *)malloc(sizeof(struct node));
		printf("Enter new data:");
		scanf("%d",&new->data);
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
		new->link=NULL;
	}
}
void insert_pos()
{
	int pos,c=1;
	struct node *new,*ptr,*p;
	printf("Enter the position to enter(after):");
	scanf("%d",&pos);
	if(header==NULL)
	{
		printf("Create node first");
		exit(1);
	}
	else
	{
		ptr=header;
		new=(struct node *)malloc(sizeof(struct node));
		printf("Enter new data:");
		scanf("%d",&new->data);
		while(pos!=c)
		{
			c++;
			p=ptr;
			ptr=ptr->link;
		}
		p->link=new;
		new->link=ptr;
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\n\n..Linked List..");
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Count");
		printf("\n4. Insert at beginning");
		printf("\n5. Insert at end");
		printf("\n6. Insert at position");
		printf("\n7. Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: display();
					break;
			case 3: count();
					break;
			case 4: insert_beg();
					break;
			case 5: insert_end();
					break;
			case 6: insert_pos();
					break;
			case 7: exit(0);
			default: printf("\nInvalid entry");
					getch();	
		}
	}
}
