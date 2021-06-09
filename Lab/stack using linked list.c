#include<stdio.h>
#include<stdlib.h>

struct node * TOP=NULL;

struct node
{
	int data;
	struct node * link;
};

void push(int val)
{
	struct node * newnode=malloc(sizeof(struct node));
	newnode->data=val;
	newnode->link=TOP;
	TOP=newnode;
}

void display()
{
	struct node * ptr;
	ptr=TOP;
	if (TOP==NULL)
	{
		printf("The stack is empty");
	}
	else{
		printf("The stack is:\n");
		while(ptr!=NULL){
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}

void pop()
{
	struct node * temp;
	temp=TOP;
	if(TOP==NULL)
	{
		printf("The stack is mepty.");
	}
	else{
		printf("The popped value is %d\n",TOP->data);
		TOP=TOP->link;
		temp->link=NULL;
		free(temp);
	}
}


void main()
{

	int x, n;
	printf("STACK USING LINKED LIST\n");
	do{
		printf("1> PUSH\n2> POP\n3> DISPLAY\n4> EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&x);
		
		switch(x)
		{
			case 1:
				printf("Enter the value to be pushed:");
				scanf("%d",&n);
				printf("The value has been pushed.\n");
				push(n);
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				printf("The final linked list is:\n");
				display();
				break;
				
				
		}
	}while(x!=4);
	getch();	
}
