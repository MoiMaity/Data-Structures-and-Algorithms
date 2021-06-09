#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int s[MAX], TOP=-1;
void push(int s[MAX], int val);
int pop(int s[MAX]);
void display();

void main()
{

	int x, n;
	printf("STACK USING ARRAY\n");
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
				push(s, n);
				display();
				break;
			case 2:
				printf("The Popped value is %d",pop(s));
				display();
				break;
			case 3:
				printf("The final linked list is:\n");
				display();
				break;
				
				
		}
	}while(x!=4);
	
}

void push(int s[MAX], int val)
{
	if(TOP==MAX-1){
	
		printf("Overflow condition\n");
	}
	else{
		
		TOP=TOP+1;
		s[TOP]=val;
	}
}

int pop(int s[MAX])
{
	int val;
	if(TOP==-1){
	
		printf("List is empty\n");
		return -1;
	}
	else{
	
		val=s[TOP];
		TOP=TOP-1;
		return val;
	}
}

void display()
{
	int i;
	if(TOP==-1){
	
		printf("Stack is empty");
	}
	else{
		printf("Elements in the stack are:\n");
		for(i=TOP;i>=0;i--){
		
			
			printf("%d\n",s[i]);
		}
	}
}