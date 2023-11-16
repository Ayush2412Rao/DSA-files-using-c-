#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	Node * nextnode;
};

Node *top=0,*newnode;

void push(int val)
{
	newnode=new Node;
	newnode->data=val;
	newnode->nextnode=top;
	top=newnode;
}

void pop()
{
	if(top==0)
	{
		cout<<"\nUnderflow Condition!!"<<endl;
		exit(0);
	}
	else
	{
		Node *temp=top;
		cout<<"\nPopped element is: "<<top->data<<endl;
		top=top->nextnode;
		delete temp;
	}
}

void display()
{
	Node *ptr;
	if(top==0)
	{
		cout<<"\nStack is empty!!"<<endl;
	}
	else
	{
		ptr=top;
		while(ptr!=0)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->nextnode;
		}
	}
}

int main()
{
	int ch,val;
	while(1)
	{
		cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit"<<endl;
		cout<<"\nEnter the choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the element: ";
				cin>>val;
				push(val);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				exit(0);		
					
		}
		
	}
	
}
