#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *header=NULL;
struct node *newn;
void create() 
{ 
	int n,i=1; 
	struct node *ptr; 
	printf("\n...creating linked list..."); 
	printf("Enter the SIZE: "); 
	scanf("%d",&n); 
 	do
	{ 
		newn=(struct node *)malloc(sizeof(struct node)); 
		printf("\nENTER DATA: "); 
		scanf("%d",&newn->data); 
		newn->link=NULL; 
		if(header==NULL) 
			header=newn;  
		else 
		{ 
			ptr=header; 
			while(ptr->link!=NULL) 
				ptr=ptr->link; 
			ptr->link=newn; 
		} 
		i++; 
	}while(i<=n); 
}
void display()
{
	struct node *ptr;
	printf("\n...displaying contents...");
	ptr=header;
	while(ptr)
	{
		printf(" %d",ptr->data);
		ptr=ptr->link;
	}
}
void delbeg()
{
	struct node *ptr;
	printf("\n...delete at beginning...");
	ptr=header;
	if(ptr==NULL)
	{
		printf("\nNo nodes exist");
		getch();
		return;
	}
	else if(ptr->link==NULL)
	{
		printf("\nOnly one node exist");
		printf("\nDeleted item:%d",ptr->data);
		header=NULL;
		free(ptr);
		getch();
	}
	else
	{
		printf("\nDeleted item:%d",ptr->data);
		header=ptr->link;
		free(ptr);
		getch();
	}
}
void delend()
{
	struct node *ptr,*p;
	printf("\n...delete at end...");
	ptr=header;
	if(ptr==NULL)
	{
		printf("\nNo nodes exist");
		getch();
		return;
	}
	else if(ptr->link==NULL)
	{
		printf("\nOnly one node exist");
		printf("\nDeleted item:%d",ptr->data);
		header=NULL;
		free(ptr);
		getch();
	}
	else
	{
		p=header;
		while(ptr->link!=NULL)
		{
			p=ptr;
			ptr=ptr->link;
		}
		p->link=NULL;
		printf("\nDeleted item:%d",ptr->data);
		free(ptr);
		getch();
	}
}
void search()
{
	int key,pos=1;
	struct node *ptr;
	printf("\n...searching for key element...");
	printf("\nEnter the search element:");
	scanf("%d",&key);
	ptr=header;
	if(ptr==NULL)
	{
		printf("\n no nodes exist");
		getch();
		return;
	}
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			printf("\nItem found at position %d",pos);
			getch();
			return;
		}
		ptr=ptr->link;
		pos++;
	}
	printf("\nItem not found");
}
void delbefore()
{
	int key;
	struct node *temp,*t2,*t3;
	printf("\n...deleting before key element");
	printf("\n Enter the element:");
	scanf("%d",&key);
	temp=header;
	if(header==NULL)
	{
		printf("\nno nodes found");
		getch();
		return;
	}
	else
	{
		while(temp->link!=NULL)
		{
			if(temp->data==key)
				break;
			t3=t2;
			t2=temp;
			temp=temp->link;
		}
		if(t2==header)
			header=header->link;
		else
			t3->link=t2->link;
		printf("\nDeleted item:%d",t2->data);
		free(t2);
	}	
}
void delafter()
{
	int key;
	struct node *temp,*t2;
	printf("\n...deleting after key...");
	printf("\nEnter the key:");
	scanf("%d",&key);
	temp=header;
	if(header==NULL)
	{
		printf("\nno nodes found");
		getch();
		return;
	}
	else
	{
		while(temp->link!=NULL)
		{
			if(temp->data==key)
				break;
			temp=temp->link;	
		}
		t2=temp->link;
		temp->link=temp->link->link;
		printf("\n Deleted item:%d",t2->data);
		free(t2);
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
		printf("\n3. Delete at beginning");
		printf("\n4. Delete at end");
		printf("\n5. Search");
		printf("\n6. Delete before key element");
		printf("\n7. Delete after key element");
		printf("\n8. Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: display();
					break;
			case 3: delbeg();
					break;
			case 4: delend();
					break;
			case 5: search();
					break;
			case 6: delbefore();
					break;
			case 7: delafter();
					break;
			case 8: exit(0);
			default: printf("\nInvalid entry");
					getch();	
		}
	}
}
