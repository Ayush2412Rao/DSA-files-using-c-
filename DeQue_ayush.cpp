#include<iostream>
#include<stdlib.h>
using namespace std;

int deque[10],front=-1,rear=-1,n=10;

void enqueuefront(int val)
{
	if((front==0 && rear==n-1)||(front==rear+1))
	{
		cout<<"\nQueue is Full!!"<<endl;
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		deque[front]=val;
	}
	else if(front==0)
	{
		front=n-1;
		deque[front]=val;
	}
	else
	{
		front--;
		deque[front]=val;
	}
}

void enqueuerear(int val)
{
	if((front==0 && rear==n-1)||(front==rear+1))
	{
		cout<<"Queue is full!!"<<endl;
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		deque[rear]=val;
	}
	else if(rear==n-1)
	{
		rear=0;
		deque[rear]=val;
	}
	else
	{
		rear++;
		deque[rear]=val;
	}
	
}
void display()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nQueue is empty!!"<<endl;
	}
	else
	{
		int i=front;
		while(i!=rear)
		{
			cout<<deque[i]<<" ";
			i=(i+1)%n;
		}
		cout<<deque[rear]<<endl;
	}
}
void getfront()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nQueue is empty!!"<<endl;
	}
	else
	{
		cout<<"\n"<<deque[front]<<endl;
	}
}
void getrear()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nQueue is empty!!"<<endl;
	}
	else
	{
		cout<<"\n"<<deque[rear]<<endl;
	}
}
void dequeuefront()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nQueue is empty!!"<<endl;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==n-1)
	{
		front=0;
	}
	else
	{
		front++;
	}
}
void dequeuerear()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nQueue is empty!!"<<endl;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
	{
		rear=n-1;
	}
	else
	{
		rear--;
	}
}

int main()
{
	int ch,val;
	
	while(1)
	{
		cout<<"\n1.Front-En-Queue\n2.Rear-En-Queue\n3.Front-De-Queue\n4.Rear-De-Queue\n5.Front Value\n6.Rear Value\n7.Display\n8.Exit"<<endl;
		cout<<"Enter the choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the element:";
				cin>>val;
				enqueuefront(val);
				break;
			case 2:
				cout<<"\nEnter the element:";
				cin>>val;
				enqueuerear(val);
				break;
			case 3:	
				dequeuefront();
				break;
			case 4:
				dequeuerear();
				break;
			case 5:
				getfront();
				break;		
			case 6:
				getrear();
				break;	
			case 7:
				display();
				break;
			case 8:
				exit(0);
				break;			
			default:
				cout<<"\nInvalid Choice!!"<<endl;	
		}
	}
}
