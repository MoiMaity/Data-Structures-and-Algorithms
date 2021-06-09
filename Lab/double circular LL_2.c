#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *newNode()
{
	struct node *temp=malloc(sizeof(struct node));
	printf("Enter the number: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void insert_begin()
{
	struct node *temp= newNode();
	struct node *ptr= NULL;
	if (head==NULL)
	{
		head=temp;
		tail=head;
		tail->next=head;
		head->prev=tail;
	}
	else
	{	
		temp->next=head;
		head->prev=temp;
		head=temp;
		head->prev=tail;
		tail->next=head;	
	}
}
void del_first()
{
	struct node *ptr=head;
	struct node *prv=NULL;
	if(head==NULL)
	{
		printf("\nThere is no element in the list\n");
	}
	else
	{
		prv=ptr;
		ptr=ptr->next;
		head=ptr;
		head->prev=tail;
		tail->next=head;
		free(prv);
	}
}
void del_last()
{
	int p=0;
	struct node *ptr=head;
	if(head==NULL)
	{
		printf("\nThere is no element in th list\n");
	}
	else
	{
		while(ptr->next!=tail->next)
		{
			p=p+1;
			ptr=ptr->next;
		}
		if(p==0)
		{
			head=NULL;
		}
		else
		{
			struct node *storeprv=ptr->prev;
			storeprv->next=NULL;
			tail=storeprv;
			tail->next=head;
			head->prev=tail;
			free(ptr);
		}
	}
}
void del_after_node()
{ 
	int n,flag=0;
	struct node *storenxt=NULL;
	struct node *ptr=head;
	struct node *storeprv=NULL;
	if(head==NULL)
	{
		printf("\nThere is no element in the list\n");
	}
	else
	{
		printf("Enter node value: ");
		scanf("%d",&n);
		do
		{
			if(ptr->data==n)
			{
				flag=1;
				break;
			}
			ptr=ptr->next;
		}while(ptr->next!=head);
		if(flag)
		{
			if(ptr->next==NULL)
			{
				printf("\nThere is no element after %d to delete!!\n",n);
			}
			else
			{
				storeprv=ptr;
				ptr=ptr->next;
				if(ptr->next==tail->next)
				{
					storeprv->next=head;
					tail=storeprv;
					head->prev=tail;
					free(ptr);
				}
				else
				{
					storenxt=ptr->next;
					storeprv->next=storenxt;
					storenxt->prev=storeprv;
					free(ptr);
				}
			}
		}
		else
		{
			printf("Not found");
		}
	}
}
void display()
{
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while((temp->next!=tail->next))
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
		printf(" %d ",temp->data);
	}
}
void main()
{
	int n;
	printf(">>>Circular doubly linked list<<<");
	while(1)
	{
		printf("\n 1.Insert node at begin. \n 2.Delete node at begin. \n 3.Delete node at end.\n 4.Delete node after a specific node. \n 5.EXIT");
		printf("\nList: ");
		display();
		printf("\nEnter Your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: insert_begin(); 
					break;
			case 2: del_first(); 
					break;
			case 3: del_last(); 
					break;
			case 4: del_after_node(); 
					break;
			case 5: exit(0);
			default: printf("\nUndefined Choice");		
		}	
	}
}


