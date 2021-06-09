#include<stdio.h>
#include<conio.h>
int binsearchiter(int arr[],int first,int last,int ele)
{
	int mid;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(arr[mid]==ele)
			return mid;
		else if(arr[mid]<ele)
			first=mid+1;
		else if(arr[mid]>ele)
			last=mid-1;
	}
	return -1;
}
int binsearchrec(int arr[],int first,int last,int ele)
{
	int mid;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(arr[mid]==ele)
			return mid;
		else if(arr[mid]<ele)
			return binsearchrec(arr,mid+1,last,ele);
		else if(arr[mid]>ele)
			return binsearchrec(arr,first,mid-1,ele);
	}
	return -1;
}
void main()
{
	int arr[]={2,4,6,7,13,16};
	int first=0,last=5,ele;
	int c,d;
	printf("Enter the element to search:");
	scanf("%d",&ele);
	printf("\n Iterative Binary Search...");
	c=binsearchiter(arr,first,last,ele);
	if(c==-1)
		printf("\nElement not found");
	else
		printf("\nElement found at index %d",c);
	printf("\n Recursive Binary Search...");
	d=binsearchrec(arr,first,last,ele);
	if(d==-1)
		printf("\nElement not found");
	else
		printf("\nElement found at index %d",d);
	getch();
}