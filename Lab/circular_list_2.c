#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *link;
};
struct Node *newnode(int Data)
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = Data;
	n->link = NULL;
	return n;
}
void delbefore(struct Node **start)
{
	int key; 
	printf("\nEnter Key: "); 
	scanf("%d", &key);
	struct Node *temp = *start, *prev = NULL, *prePrev = NULL;
	int flag = 0;
	do
	{
		if (temp->data == key)
		{
			flag = 1; 
			break;
		}
		prePrev = prev;
		prev = temp;
		temp = temp->link;
	}while (temp != *start);
	if (flag)
	{
		if (temp == *start) 
		{
			struct Node *travel = *start, *prev2 = NULL;
			do
			{
				prev2 = travel;
				travel = travel->link;
			}while(travel->link != *start);
			prev2->link = travel->link;
			free(travel);
		}
		else if(prev == *start)  
		{
			struct Node *travel = *start, *prev2 = NULL;
			do
			{
				prev2 = travel;
				travel = travel->link;
			}while(travel->link != *start);
			*start = (*start)->link;
			travel->link = *start;
			free(prev);
		}
		else
		{
			prePrev->link = prev->link;
			free(prev);
		}
	}
	else
		printf("\nError!!!...Key Not Found");
}
void delafter(struct Node **start)
{
	int key; 
	printf("\nEnter Key: ");
	scanf("%d", &key);
	struct Node *temp = *start;
	int flag = 0;
	do
	{
		if (temp->data == key)
		{
			flag = 1;
			break;
		}
		temp = temp->link;
	}while (temp != *start);
	if (flag)
	{
		if (temp->link == *start) 
		{
			struct Node *dummy = *start;
			*start = (*start)->link;
			temp->link = *start;
			free(dummy);
		}
		else
		{
			struct Node *xNode = temp->link;
			temp->link = temp->link->link;
			free(xNode);
		}
	}
	else
		printf("\nError!!!..Key Not Found");
}
void insbefore(struct Node **start)
{
	int key; 
	printf("\nEnter Key: "); 
	scanf("%d", &key);
	struct Node *temp = *start, *prev = NULL;
	int flag = 0;
	do
	{
		if (temp->data == key)
		{
			flag = 1; 
			break;
		}
		prev = temp;
		temp = temp->link;
	}while (temp != *start);
	if (flag)
	{
		int Val; 
		printf("\nEnter the Data: "); 
		scanf("%d", &Val);
		struct Node *aNode = newnode(Val);
		if (temp == *start)   
		{
			struct Node *travel = *start;
			do
			{
				travel = travel->link;
			}
			while (travel->link != *start);
			aNode->link = *start;
			travel->link = aNode;
			*start = aNode;
		}
		else
		{
			aNode->link = prev->link;
			prev->link = aNode;
		}
	}
	else
		printf("\nError!!!..Key Not Found");
}
void insafter(struct Node **Start)
{
	int key; 
	printf("\nEnter Key: "); 
	scanf("%d", &key);
	struct Node *temp = *Start;
	int flag = 0;
	do
	{
		if (temp->data == key)
		{
			flag = 1; 
			break;
		}
		temp = temp->link;
	}while (temp != *Start);
	if (flag)
	{
		int Val; 
		printf("Enter the Data: "); 
		scanf("%d", &Val);
		struct Node *aNode = newnode(Val);
		aNode->link = temp->link;
		temp->link = aNode;
	}
	else
		printf("Error!!!..Key Not Found");
}
void Creation(struct Node **Head)
{
	printf("...Creating a Circular List First...\n");
	int N; 
	printf("\nEnter number of elements: "); 
	scanf("%d", &N);
	int Arr[N];
	printf("Enter the elements: ");
	scanf("%d", &Arr[0]);
	*Head = newnode(Arr[0]);
	struct Node *last = *Head;
	int i;
	for(i = 1; i < N; i++)
	{
		scanf("%d", &Arr[i]);
		struct Node *n = newnode(Arr[i]);
		last->link = n;
		last = n;
	}
	last->link = *Head;
	printf("\nList Created");
}
void Display(struct Node *Start)
{
	struct Node *disp = Start;
	printf("Current LIST: ");
	if(disp==NULL)
		printf("List Empty");
	else
	{
		do
		{
			printf("%d ", disp->data);
			disp = disp->link;
		}while(disp!=Start);
	}
}
int main()
{
	struct Node *start = NULL;
	Creation(&start);
	while (1)
	{
		system("CLS");
		printf("\n CIRCULAR LINKED LIST");
		printf("\n1. Insert After 'KEY'\n2. Insert Before 'KEY'");
		printf("\n3. Delete After 'KEY'\n4. Delete Before 'KEY'\n5. Exit\n\n");
		Display(start);
		printf("\n\nEnter Your Choice: ");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
			case 1: insafter(&start); 
					Display(start);
					break;
			case 2: insbefore(&start); 
					Display(start);
					break;
			case 3: delafter(&start); 
					Display(start);
					break;
			case 4: delbefore(&start);
					Display(start);
					break;
			case 5: exit(0);
		}
		getch();
	}
	return 0;
}
