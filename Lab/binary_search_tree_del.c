#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

int createtree(struct node *root, int data)
{
	if (root == NULL)
		{
			struct node *temp;
			temp=malloc(sizeof(struct node));
			temp->data = data;
			temp->left = temp->right = NULL;
			return temp;
		}
	if (data < (root->data))
	{
		root->left = createtree(root->left, data);
	}
	else if (data > root->data)
	{
		root -> right = createtree(root->right, data);
	}
	return root;
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("  %d",root->data);
		inorder(root->right);
	}
}

int deleteNode(struct node* root, int data)
{

    if (root == NULL)
	{
        return root;
	}
    if (data < root->data)
	{
        root->left = deleteNode(root->left, data);
	}
    else if (data > root->data)
	{
        root->right = deleteNode(root->right, data);
	}
    else
	{
        if (root->left == NULL)
		{
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
		{
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

void postorder(struct node* root) 
{ 
    if (root)
	{     
    	postorder(root->left);   
    	postorder(root->right); 
    	printf(" %d ", root->data); 
 	}
}

void preorder(struct node* root) 
{ 
    if (root)
	{ 
     	printf(" %d ", root->data);   
     	preorder(root->left);   
     	preorder(root->right); 
 	}
}

void main()
{
	int ch,n,i,data,key;
	struct node* root=NULL;
	do
	{
		printf("\n1.Insertion in Binary Search Tree");
		printf("\n2.Display\n3.Delete\n4.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the range : " );
				scanf("%d", &n);
				printf("\nEnter the elements to create BINARY SEARCH TREE\n");
				for(i=0; i<n; i++)
				{			
					scanf("%d", &data);
					root=createtree(root, data);
				}
				break;
			case 2:
				printf("\nInorder Traversal: \n");
				inorder(root);	
				printf("\nPreorder Traversal: \n");			
				preorder(root);	
				printf("\nPostorder Traversal: \n");	
				postorder(root);		
				break;	
			case 3:
				printf("Deletion:\n");
				printf("enter the number to delete:");
				scanf("%d",&key);
				deleteNode(root, key);
				break;
			case 4:
				exit(0);	
			default:
				printf("\n Incorrect option");
		}
	}while(ch!=4);
	getch();
}
