#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int l,int h)
{
	int p,i,j;
	p=a[h];
	i=l-1;
	for(j=l;j<=h-1;j++)
	{
		if(a[j]<p)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[h]);
	return (i+1);
}
void quicksort(int a[],int l,int h)
{
	int pi;
	if(l<h)
	{
		pi=partition(a,l,h);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,h);
	}
}
void main()
{
	int a[]={10,30,50,40,90,80,70};
	int n=7,i;
	printf("Quick Sort...");
	quicksort(a,0,n-1);
	printf("\nSorted..");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
	getch();
}
	
