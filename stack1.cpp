#include<iostream>
#include<stdlib.h>
using namespace std;
int stack[50],top=-1,val,n;

void push()
{
	if(top==n-1)
	{
		cout<<"\nOverflow ->Stack is full!!"<<endl;
		exit(0);
	}
	else
	{
		cout<<"\nEnter the element to enter in the stack: "<<endl;
		cin>>val;
		top++;
		stack[top]=val;
	}
}

void pop()
{
	if(top==-1)
	{
		cout<<"\nUnderflow->Stack is empty!!"<<endl;
	}
	else
	{
		top=top-1;
	}
}

void display()
{
	if(top==-1)
	{
		cout<<"\nStack is empty!!"<<endl;
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			cout<<stack[i]<<""<<endl;
		}
	}
}

void peek()
{
	if(top==-1)
	{
		cout<<"\nStack is empty!!"<<endl;
	}
	else
	{
		cout<<"\nTop element is: "<<stack[top]<<endl;
	}
}
void stack_info()
{
	if(top==-1)
	{
		cout<<"\nUnderflow!!"<<endl;
	}
	else if(top==n-1)
	{
		cout<<"\nOverflow!!"<<endl;
	}
	else
	{
		cout<<"\nIn-Process!!"<<endl;
	}
}
int main()
{
	int i;
	cout<<"\nEnter 1 to continue and 0 to exit: "<<endl;
	cin>>i;
	while(i==1)
	{
		int a;
		cout<<"\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Stack Info\n6.Exit"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1:
				cout<<"\nEnter the number of elements you want to enter in the stack: "<<endl;
				cin>>n;
				for(int i=1;i<=n;i++)
				{
					push();
				}
				break;
			case 2:
				pop();
				break;	
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				stack_info();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"\nInvalid Choice!!";					
		}
	}
	
}
