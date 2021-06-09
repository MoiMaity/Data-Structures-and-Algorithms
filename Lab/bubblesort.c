#include<stdio.h>
#include<conio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubblesort(int a[],int n)
{
	int i,j;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}

void main()
{
	int arr[]={4,3,1,5,2};
	int n=5,i;
	bubblesort(arr,n);
	printf("\nSorted array...");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	getch();
}
