#include<iostream>
#include<algorithm>
using namespace std;

void minheapify(int arr[], int n, int i)
{
	int smallest = i;
	int left = 2*i;
	int right = 2*i+1;
	
	if(left < n && arr[left] < arr[smallest])
	{
		smallest = left;
	}
	if(right < n && arr[right] < arr[smallest])
	{
		smallest = right;
	}
	
	if(smallest!=i)
	{
		int temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
		
		minheapify(arr, n, smallest);
	}
}

void buildheap(int arr[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		minheapify(arr,n,i);
	}
}

void minsort(int arr[], int n)
{
	buildheap(arr, n);
	
	int i;
	for(i=n-1;i>0;i--)
	{
		int temp = arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		
		minheapify(arr,n,0);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n");
	
	minsort(arr,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
