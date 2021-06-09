#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node
{
	int data;
	struct node *next;
};
struct node *start,*ptr,*end;
void create()
{
	int data;
	c++;
	printf("\n..creating..");
	printf("\nEnter data:");
	scanf("%d",&data);
	if(c==1)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->data=data;
		start=ptr;
		ptr->next=ptr;
	}
	else
	{
		ptr->next=(struct node *)malloc(sizeof(struct node));
		ptr=ptr->next;
		ptr->data=data;
		ptr->next=start;
	}
}
void insertbeg()
{
	int data;
	c++;
	printf("\n..Inserting at beginning..");
	printf("\nEnter data:");
	scanf("%d",&data);
	end=(struct node *)malloc(sizeof(struct node));
	end->data=data;
	end->next=start;
	start=end;
}
void insertend()
{
	int data,i;
	c++;
	printf("\n...Inserting at end...");
	printf("\nEnter data:");
	scanf("%d",&data);
	end=(struct node *)malloc(sizeof(struct node));
	end->data=data;
	ptr=start;
	for(i=1;i<c;i++)
	{
		ptr=ptr->next;
	}
	end->next=start;
	ptr->next=end;
}
void delbeg()
{
	printf("\n..deleting from beginning..");
	if(start==NULL)
	{
		printf("\nList is empty..");
		return;
		getch();
	}
	else
	{
		end=start;
		start=start->next;
		free(end);
		c--;
	}
}
void delend()
{
	int i;
	printf("\n...deleting from end..");
	ptr=start;
	for(i=1;i<c;i++)
		ptr=ptr->next;
	end=ptr->next;
	ptr->next=start;
	free(end);
	c--;
}
void delall()
{
	printf("\n...deleting all...");
	if(start==NULL)
	{
		printf("\n..List is empty...");
		return;
		getch();
	}
	else
	{
		struct node *temp,*temp2;
		temp=start;
		do
		{
			temp2=temp;
			free(temp2);
			temp=temp->next;
		}while(temp->next!=start);
		printf("\n List deleted");
	}
	start=NULL;
}
void display()
{
	int i;
	end=start;
	printf("\n..display..");
	printf("\nDisplaying the nodes...");
	ptr=end;
	for(i=1;i<=c;i++)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
	if(c==0)
		printf("\nThere are no elements");
}
void main()
{
	int ch;
	while(1)
	{
		printf("\n\n.....Circular Linked List.....");
		printf("\n1. Create");
		printf("\n2. Insert at beginning");
		printf("\n3. Insert at end");
		printf("\n4. Delete at front");
		printf("\n5. Delete at end");
		printf("\n6. Delete all");
		printf("\n7. Display");
		printf("\n8. Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: insertbeg();
					break;
			case 3: insertend();
					break;
			case 4: delbeg();
					break;
			case 5: delend();
					break;
			case 6:	delall();
					break;
			case 7: display();
					break;
			case 8: exit(0);
			default: printf("\ngive correct input");
		}
	}
	getch();
}
