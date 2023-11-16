#include<iostream>
#include<stdlib.h>
using namespace std;

int queue[100],front=-1,rear=-1,n=100;

void enqueue(int val)
{
	if(rear==n-1)
	{
		cout<<"\nOverflow Condition!!"<<endl;	
	}	
	else if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		queue[rear]=val;
	}
	else
	{
		rear++;
		queue[rear]=val;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nStack is empty!!"<<endl;
	}
	else if(front==rear)
	{
		cout<<"\nDe-Queued element is: "<<queue[front]<<endl;
		front=rear=-1;
	}
	else
	{
		cout<<"\nDe-Queued element is: "<<queue[front];
		front++;
	}
}

void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		cout<<"\nStack is empty!!"<<endl;
	}
	else
	{
		/*while(front<=rear)
		{
			cout<<" "<<queue[front];
		}
		*/
		for(i=front;i<=rear;i++)
		{
			cout<<" "<<queue[i];
		}
	}
}

void peek()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nStack is empty!!"<<endl;
	}
	else
	{
		cout<<"\nPeek value is: "<<queue[front]<<endl;
	}
}

int main()
{
	int ch,val;
	while(1)
	{
		cout<<"\n1.En-queue\n2.De-queue\n3.Peek\n4.Display\n5.Exit"<<endl;
		cout<<"\nEnter the choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the element: ";
				cin>>val;
				enqueue(val);
				break;
			
			case 2:
				dequeue();
				break;	
				
			case 3:
				peek();
				break;
			
			case 4:
				display();
				break;
				
			case 5:
				exit(0);		
		}
	}
}
