#include <stdio.h>
#include <conio.h>
#define MAX 10

int queue[MAX];
int front=-1,rear=-1;
void insert(void);
int delete(void);
void display(void);
int main()
{
    int option,val;
    do
    {
        printf("\n Circular Queue using Array");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter choice");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                insert();
            break;
            case 2:
                val=delete();
                if(val!=-1)
                    printf("\n The number is deleted %d",val);
            break;
            case 3:
                display();
            break;
        }
    }while(option!=4);
    getch();
    return 0;
}

void insert()
{
    int num;
    printf("\n Enter data to insert");
    scanf("%d",&num);
    if(front==0 && rear==MAX-1)
        printf("\n Overflow");
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=num;
    }
    else if(rear==MAX-1 && front!=0)
    {
        rear=0;
        queue[rear]=num;
    }
    else
    {
        rear++;
        queue[rear]=num;
    }
}

int delete()
{
    int val;
    if(front==-1 && rear==-1)
    {
        printf("\n Underflow");
        return -1;
    }
    val=queue[front];
    if(front==rear)
        front=rear=-1;
    else
    {
        if(front==MAX-1)
            front=0;
        else
            front++;
    }
    return val;
}

void display()
{
    int i;
    printf("\n");
    if(front==-1 && rear==-1)
    	printf("\n Queue is empty");
    else
    {
        if(front<rear)
        {
            for(i=front;i<=rear;i++)
            printf("\t %d",queue[i]);
        }
        else
        {
            for(i=front;i<MAX;i++)
            printf("\t %d",queue[i]);
            for(i=0;i<=rear;i++)
            printf("\t %d",queue[i]);
        }
    }
}
