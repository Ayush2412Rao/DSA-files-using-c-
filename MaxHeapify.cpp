#include<iostream>
#include<algorithm>
using namespace std;

void maxheapify(int arr[],int n,int i)
{
	int largest=i;
	int left=(2*i)+1;
	int right=(2*i)+2;
	if(left<n && arr[largest]<arr[left])
	{
		largest=left;
	}
	if(right<n && arr[largest]<arr[right])
	{
		largest=right;
	}
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		
	}
}

void buildmaxheap(int arr[],int n)
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
	for(i=n;i>0;i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		
		maxheapify(arr, i, 0);
	}
}

void insertheap(int arr[],int n,int value)
{
	n=n+1;
	arr[n]=value;
	int i=n;
	while(i>1)
	{
		int parent=i%2;
		if(arr[parent]<arr[i])
		{
			int temp=arr[i];
			arr[i]=arr[parent];
			arr[parent]=temp;
			i=parent;
		}
		else
		{
			return;
		}
	}
}

void bubblesort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
  
        // Last i elements are already 
        // in place 
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
} 

int main()
{
	int n;
	cout<<"\nEnter the number of nodes of the heap: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the element:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int i=0;
	
	buildmaxheap(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
	
}

/*void maxheapify*/
