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
	printf("Enter the number: ");
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
void ins_after_node()
{	
	int n,ok=0;
	struct node *temp=newNode();
	struct node *ptr=head;
	struct node *storenxt=NULL;
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
				ok=1;
				break;
			}
			ptr=ptr->next;
		}while(ptr!=NULL);	
		if(ok)
		{
			if(ptr->next==NULL)
			{
				ptr->next=temp;
				temp->prev=ptr;
			}
			else
			{
				storenxt=ptr->next;
				ptr->next=temp;
				temp->prev=ptr;
				temp->next=storenxt;
				storenxt->prev=temp;
			}
		}
		else
		{
			printf("Not found");
		}	
	}
}
void ins_before_node()
{ 
	int n,ok=0;
	struct node *temp=newNode();
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
				ok=1;
				break;
			}
			ptr=ptr->next;
		}while(ptr!=NULL);
		if(ok)
		{
			if(ptr->prev==NULL)
			{
				temp->next=head;
	    		head->prev=temp;
	   		 	head=temp;;
			}
			else
			{
				storeprv=ptr->prev;
				storeprv->next=temp;
				temp->prev=storeprv;
				ptr->prev=temp;
				temp->next=ptr;
			}
		}
		else
		{
			printf("Not found");
		}
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
		while(ptr->next!=NULL)
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
		free(ptr);
		}
	}
}
void del_after_node()
{
	int n,ok=0;
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
				ok=1;
				break;
			}
			ptr=ptr->next;
		}while(ptr!=NULL);
		if(ok)
		{
			if(ptr->next==NULL)
			{
				printf("\nThere is no element after %d to delete!!\n",n);
			}
			else
			{
				storeprv=ptr;
				ptr=ptr->next;
				if(ptr->next==NULL)
				{
					storeprv->next=NULL;
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
void del_before_node()
{
	int n,ok=0;
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
				ok=1;
				break;
			}
			ptr=ptr->next;
		}while(ptr!=NULL);
		if(ok)
		{
			if(ptr->prev==NULL)
			{
				printf("\nThere is no element before %d to delete!!\n",n);
			}
			else
			{
				storenxt=ptr;
				ptr=ptr->prev;
				if(ptr->prev==NULL)
				{
					head=storenxt;
					head->prev=NULL;
					free(ptr);
				}
				else
				{
					storeprv=ptr->prev;
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
		printf(" list is empty ");
	}
	else
	{
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
	printf("....DOUBLE LINKED LIST....");
	while(1)
	{
		printf("\n 1.Insert node at begin. \n 2.Insert node after a given node. \n 3.Insert node before a given node. \n 4.Delete first node. \n 5.Delete last node. \n 6.Delete node after a given node. \n 7.Delete node before a given node. \n 8.Exit.");
		printf("\nList: ");
		display();
		printf("\nEnter Your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: insert_begin(); 
					break;
			case 2: ins_after_node();
					break;
			case 3: ins_before_node();
					break;
			case 4: del_first();
					break;
			case 5: del_last();
					break;
			case 6: del_after_node();
					break;
			case 7: del_before_node();
					break;
			case 8: exit(0);
			default: printf("\nInvalid Choice");		
		}	
	}
}

