#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node * nextnode;
	Node * prevnode;
};

Node *head=0,*newnode,*temp,*temp1;

void create()
{
	int n;
	cout<<"Enter the no. of elements of the list:";
	cin>>n;

	cout<<"\nEnter the elements:";
	while(n>=1)
	{
		newnode= new Node;
		cin>>newnode->data;
		newnode->nextnode=0;
		newnode->prevnode=0;
		if(head==0)
		{
			head=newnode;
			temp=head;
		}
		else
		{
			temp->nextnode=newnode;
			newnode->prevnode=temp;
			temp=newnode;
		}
		n--;
	}
}

void insert_str(Node*head)
{
	temp=head;
	newnode=new Node;
	cout<<"\nEnter the element to add at begining:";
	cin>>newnode->data;
	newnode->nextnode=temp;
	temp->prevnode=newnode;
	head=newnode;
}

void insert_end(Node*head)
{
	temp=head;
	while(temp->nextnode!=0)
	{
		temp=temp->nextnode;
	}
	newnode=new Node;
	cout<<"\nEnter the element to add at the end:";
	cin>>newnode->data;
	temp->nextnode=newnode;
	newnode->prevnode=temp;
	newnode->nextnode=0;
}


void insert_pos(Node*head,int pos)
{
	
	int i=1;
	temp=head;
	pos--;
	while(i<pos)
	{
		temp=temp->nextnode;
		i++;
	}
	newnode=new Node;
	cout<<"\nEnter the element:";
	cin>>newnode->data;
	newnode->prevnode=temp;
	newnode->nextnode=temp->nextnode;
	temp->nextnode=newnode;
	
	
}

void del_str(Node*head)
{
	cout<<"\nDeleting the first element!!\n";
	temp=head;
	
	if(head==0)
	{
		delete head;
	}
	else
	{
		head=head->nextnode;
		head->prevnode=0;
		delete temp;
	}
}
void del_end(Node*head)
{
	cout<<"\nDeleting the last element!!\n";
	temp=head;
	while(temp->nextnode!=0)
	{
		temp=temp->nextnode;
	}
	
	temp1=temp;
	temp=temp->prevnode;
	temp->nextnode=0;
	delete temp1;
	
}

void del_pos(Node*head,int pos)
{
	temp=head;
	int i=1;
	pos--;
	while(i<pos)
	{
		temp=temp->nextnode;
		i++;
	}
	temp1=temp->nextnode;
	temp->nextnode=temp1->nextnode;
	temp1=temp1->nextnode;
	temp1->prevnode=temp;
	delete temp1;
}

void display()
{
	temp=head;
	cout<<"\nPrinting in forward!!";
	while(temp!=0)
	{
		cout<<"\n"<<temp->data<<endl;
		temp=temp->nextnode;
	}
	temp=newnode;
	cout<<"\nPrinting in backward!!";
	while(temp!=0)
	{
		cout<<"\n"<<temp->data<<endl;
		temp=temp->prevnode;
	}
}


int main()
{
	int ch,pos;
	while(1)
	{
		cout<<"\n1.Create\n2.Insert at Start\n3.Insert at End\n4.Insert at any position\n5.Delete at Start\n6.Delete at End\n7.Delete from any position\n8.Display in forward and backward\n9.Exit";
		cout<<"\nEnter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				create();
				break;
			
			case 2:
				insert_str(head);
				break;
			
			case 3:
				insert_end(head);
				break;
			
			case 4:
				cout<<"\nEntering element at entered position:";
				cin>>pos;
				insert_pos(head,pos);
				break;
			
			case 5:
				del_str(head);
				break;
			
			case 6:
				del_end(head);
				break;
				
			case 7:
				cout<<"\nEnter the position to delete:"<<endl;
				cin>>pos;
				del_pos(head,pos);
				break;
			
			case 8:
				display();
				break;
			
			case 9:
				exit(0);
				break;
			
			default:
				cout<<"\nInvalid choice!!"<<endl;
												
		}
	}
}
