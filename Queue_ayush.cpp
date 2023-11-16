#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node *nextnode;
};
Node *front=0,*rear=0,*newnode;

void enqueue(int val)
{
	if(front==0 && rear==0)
	{
		newnode=new Node;
		newnode->data=val;
		newnode->nextnode=rear;
		rear=newnode;
		front=newnode;
	}
	else
	{
		newnode=new Node;
		newnode->data=val;
		newnode->nextnode=0;
		rear->nextnode=newnode;
		rear=newnode;
	}
}

void dequeue()
{
	if(front==0 && rear==0)
	{
		cout<<"\nUnderflow"<<endl;
	}
	else
	{
		Node *temp;
		temp=front;
		front=front->nextnode;
		delete temp;
	}
}

void display()
{
	if(front==0 && rear==0)
	{
		cout<<"\nStack is empty"<<endl;
	}
	else
	{
		Node *ptr;
		ptr=front;
		while(ptr!=0)
		{
			cout<<" "<<ptr->data;
			ptr=ptr->nextnode;
		}
	}
}

void peek()
{
	if(front==0 && rear==0)
	{
		cout<<"\nUnderflow"<<endl;
	}
	else
	{
		cout<<"\nPeek Value is: "<<front->data<<endl;
	}
}

int main()
{
	int ch,val;
	while(1)
	{
		cout<<"\n1.En-Queue\n2.De-Queue\n3.Display\n4.Peek\n5.Exit"<<endl;
		cout<<"\nEnter the choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the element:";
				cin>>val;
				enqueue(val);
				break;
			
			case 2:
				dequeue();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				peek();
				break;
			
			case 5:
				exit(0);
				break;
			
			default:
				cout<<"\nInvalid choice!!";					
		}
	}
}
