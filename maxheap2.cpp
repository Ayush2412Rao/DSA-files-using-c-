#include <stdio.h>


//insertion and sorting.

void maxheapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2*i;
	int right = (2*i)+1;
	
	if(left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	else if(right < n && arr[right] > arr[largest])
	{
		largest = right;
	}
	
	if(largest!=i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		
		maxheapify(arr, n, largest);	
	}
}

void buildmaxheap(int arr[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		maxheapify(arr,n,i);
	}
}

void heapsort(int arr[], int n)
{
	buildmaxheap(arr, n);
	
	int i;
	for(i=n-1;i>0;i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		
		maxheapify(arr, i, 0);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n");
	buildmaxheap(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	heapsort(arr, n);
	
	printf("Sorted heap is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
