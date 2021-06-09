#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *newNode()
{
    printf("\nEnter Data: "); 
    int val; 
    scanf("%d",&val);
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
	    if (dummy)
	    {
	        	dummy->prev = dummy->next = NULL;
	        	dummy->data = val;
	        	return dummy;
	    }
	    else
	        	printf("\nNode Not Created");
}
struct Node *insert_end(struct Node **Start, struct Node *Last)
{
    struct Node *dummy = newNode();
    if(Last == NULL)
    {
        *Start = dummy;
        (*Start)->prev = (*Start)->next = dummy;
        Last = dummy;
    }
    else
    {
        dummy->next = Last->next;
        Last->next = dummy;
        dummy->prev = Last;
        (*Start)->prev = dummy;
        Last = dummy;
    }  
    return Last; 
}
struct Node *insert_begin(struct Node **Start, struct Node *Last)
{
     struct Node *dummy = newNode();
     if(Last == NULL)
    {
        *Start = dummy;
        (*Start)->prev = (*Start)->next = dummy;
        Last = dummy;
    }
    else
    {
        dummy->next = *Start;
        (*Start)->prev = dummy;
        dummy->prev = Last;
        *Start = dummy;
        Last->next = dummy;
    }
    return Last;
}
void Display(struct Node *Head)
{
    if (!(Head))
	        printf("\n\nList is Empty");
    	else
	    {
        struct Node *Start = Head;
		       printf("\nForward List: ");
	        	do
		        {
			            printf("%d ", Start->data);
			            Start = Start->next;
		        }while(Start != Head);
	    	printf("\nBackward List: ");
		    struct Node *ptr = Head->prev;
		    do
	    	{
		        	printf("%d ",ptr->data);
		        	ptr = ptr->prev;
		    }while(ptr != Head->prev);
	    }
}
int main()
{
    struct Node *Start = NULL, *last = NULL;
    while (1)
	    {
	        	printf("1.Insert_Beginning\n2.Insert_End\n3.Exit\n");
    	    	Display(Start);
	        	printf("\n\nEnter Your Choice: "); int choice;
    	    	scanf("%d", &choice);
		        switch (choice)
	        	{
		            case 1: last = insert_begin(&Start, last); break;
	        	    case 2: last = insert_end(&Start, last); break;
             case 3: exit(0);
	        	    default: printf("\nUndefined Choice");
        		}
		        getch();
    	}
	    return 0;
}
