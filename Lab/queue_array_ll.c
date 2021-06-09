#include<stdio.h>
#include<stdlib.h>
# define N 5
int queue[N], f=-1, r=-1;

struct node
{
	int data;
	struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *newNode()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	return temp;
}
void enqueue()
{
	struct node *temp=newNode();
	if(front==NULL&&rear==NULL)
	{
		front=rear=temp;
		front->link=rear->link=NULL;
	}
	else
	{
		rear->link=temp;
		rear=temp;
		rear->link=NULL;
	}
}
void dequeue()
{
	if(front==NULL&&rear==NULL)
	{
		printf("UNDERFLOW!!!\n");
	}
	else
	{
		struct node *temp;
		temp=front;
		front=front->link;
		free(temp);
	}
}

void display()
{
	struct node *temp=front;
	if(front==NULL&&rear==NULL)
	printf("EMPTY!!");
	else
	{
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}
int linked()
{
	int ch,value,a=1;
	printf(">>>QUEUE USING LINKED LIST<<<\n");
	while(a==1)
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Queue is : ");
		display();
		printf("\n");
		printf("Enter choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
					break;
			case 2:dequeue();
					break;
			case 3:display();
					break;
			case 4:a=0;
					break;
			default:printf("INVALID CHOICE!!!");					
		}
		printf("\n");
	}
}

int number()
{
	int num;
	printf("Enter number: ");
	scanf("%d",&num);
	return (num);
}

void aenqueue()
{
	if(r==N-1)
	{
		printf("Overflow");
	}
	else if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		queue[r]=number();
	}
	else
	{
		r++;
		queue[r]= number();
	}
}

void adequeue()
{
	if((f==-1 && r==-1)||(f>r))
	{
		printf("Underflow\n");
	}
	else if(f==r)
	{
		f==-1;
		r=-1;
	}
	else
	{
		f++;
	}
}

void adisplay()
{	
	int i;
    if((f==-1 && r==-1)||(f>r))
	{
    	printf("Empty");
	}
	else
	{
    	for(i=f;i<=r;i++)
		{
    		printf(" %d ",queue[i]);
		}
	}
} 

int array()
{
	printf(">>QUEUE USING ARRAY<<\n");
	int ch=1,n;
	while(ch)
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Queue: ");
		adisplay();
		printf("\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: aenqueue();
					break;
			case 2: adequeue();
					break;
			case 3: adisplay();
					break;
			case 4: ch=0;
					break;
		}
	}
}

void main()
{
    int c,x=1;
    while(x==1)
	{
    	printf("Press: \n 1.Queue using array\n 2.Queue using linked list\n 3.Exit");
    	printf("\nYour choice: ");
    	scanf("%d",&c);
    	switch(c)
		{
        	case 1: array();
					break;
        	case 2: linked();
					break;
        	case 3: x=0;
					break;
    	}
	}
    printf("BYE BYE!!");
}

