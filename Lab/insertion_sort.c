#include<stdio.h>
#include<conio.h>
void insertionsort(int a[],int n)
{
	int i,j,next;
	for(i=1;i<n;i++)
	{
		next=a[i];
		for(j=i-1;j>=0&&a[j]>next;j--)
			a[j+1]=a[j];
		a[j+1]=next;
	}
}

void main()
{
	int arr[]={5,3,1,6,7};
	int n=5,i;
	insertionsort(arr,n);
	printf("\nSorted array...");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	getch();
}
