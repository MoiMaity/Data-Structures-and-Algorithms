#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
int c=0;

struct node *newNode()
{
	struct node *temp=malloc(sizeof(struct node));
	printf("Enter the number: ");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;	
	return temp;
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

void postorder(struct node *root) 
{ 
    if(root)
	{
		postorder(root->left); 
	    postorder(root->right); 
  		printf(" %d ", root->data); 
    }
}

void preorder(struct node *root) 
{ 
    if(root)
	{
    	printf(" %d ", root->data);   
    	preorder(root->left);   
    	preorder(root->right); 
    }
}

void small(struct node *root)
{
    if(root)
	{
        struct node *temp = root;
        while(temp->left!=NULL)
		{
            temp=temp->left;
        }
        printf("%d",temp->data);   
    }
}

void large(struct node *root)
{
    if(root)
	{
        struct node *temp = root;
        while(temp->right!=NULL)
		{
            temp=temp->right;
        }
        printf("%d",temp->data);       
    }
}

int nodecount(struct node *root)
{
    if(root==NULL) 
		return 0;
    return(1 + nodecount(root->left) + nodecount(root->right));
}

int leaf(struct node *root)
{
    if(root)
	{
        if(root->right==NULL && root->left==NULL)
        {
			c++;
		}
        else
		{
            if(root->left)
			{
                leaf(root->left);
			}
            if(root->right)
			{
                leaf(root->right);
			}
        }
    }
    return c;
}

int height(struct node* root)
{
	int left_height, right_height;
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		left_height=height(root->left);
		right_height=height(root->right);
		if (left_height>right_height)
		{
			return(left_height+1);
		}
		else
		{
			return(right_height+1);
		}
	}
}

void mirror_image(struct node * root)
{
	struct node *ptr;
	if (root!=NULL)
	{
		mirror_image(root->left);
		mirror_image(root->right);
		ptr=root->left;
		root->left=root->right;
		root->right=ptr;	
	}
}

struct node *delete(struct node *root)
{
    if(root!=NULL)
    {
        delete(root->left);
        delete(root->right);
        free(root);
    }
}

void insert()
{
    int n,i;
    printf("How many numbers: ");
    scanf("%d",&n);
    printf("Enter the numbers: ");
    for(i=1;i<=n;i++)
	{
        struct node *a=newNode();
        if (i==1)
		{
            root=a;
        }
        else
		{
            struct node *b=root;
            while(1)
			{
                if(a->data > b->data)
				{
					if(b->right == NULL)
					{					
						b->right = a;
						break;
					}
					else
						b = b->right;
				}
				else
				{
					if(b->left == NULL)
					{						
						b->left = a;
						break;
					}
					else
						b = b->left;										
				}		
            }
        }
    }
}

void main()
{
	int c=1,ch,n;    
	insert();
	while(c!=0)
	{
		printf("\n1.Inorder \n2.Preorder \n3.Postoder \n4.Smallest element \n5.Largest element \n6.Number of nodes \n7.Number of external nodes \n8.Number of internal nodes \n9.Height \n10.Mirror \n11.Delete the tree \n12.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
    		case 1: printf("The inorder binary search tree is:");
        	    	inorder(root);
					break;
    		case 2: printf("\nThe preorder binary search tree is:");
         	 	  	preorder(root);
					break;
    		case 3: printf("\nThe postorder binary search tree is:");
          		  	postorder(root);
					break;
    		case 4: printf("\nSmallest element:  ");
            		small(root);
					break;
    		case 5: printf("\nlargest element:  ");
            		large(root);
					break;
    		case 6: n=nodecount(root);
            		printf("Number of nodes: %d",n);
					break;
    		case 7: n=leaf(root);
            		printf("Number of external nodes: %d",n);
					break;
    		case 8: printf("Number of internal nodes= %d",(nodecount(root)-leaf(root)));
					break; 
    		case 9: n=height(root);
            		printf("Height: %d",n);
					break;
    		case 10:printf("mirror image:\n");
					mirror_image(root);
            		inorder(root);
					break;
    		case 11:delete(root);
           			printf("Tree deleted!!");
    		case 12:printf("Thank you! Bye!");
            		c=0;
					break;
    		default: printf("Wrong Input.");        
		}
	}
	getch();
}
