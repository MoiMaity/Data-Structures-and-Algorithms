#include<stdio.h>
#include<conio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void selectionsort(int a[],int n)
{
	int i,j,max;
	for(i=n-1;i>=1;i--)
	{
		max=i;
		for(j=0;j<i;j++)
		{
			if(a[j]>=a[max])
				max=j;
		}
		swap(&a[i],&a[max]);
	}
}

void main()
{
	int arr[]={5,3,1,6,3};
	int n=5,i;
	selectionsort(arr,n);
	printf("\nSorted array...");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	getch();
}
