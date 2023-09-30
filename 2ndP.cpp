#include<iostream>
#include<iomanip>
using namespace std;
struct link
{
	int data;
	struct link *next;
};
struct link *start1=NULL,*start2=NULL;//link *start=NULL
link *current,*node;
void create(link *&start)
{
	int n;
	cout<<"How many nodes you want to create";
	cin>>n;
	cout<<"Enter all elements";
	for(int i=0;i<n;i++)
	{
		node=new link();
		cin>>node->data;
		node->next=NULL;
		if(start==NULL)
		{
			start=node;
			current=node;
		}
		{
			current->next=node;
			current=node;
		}
	}
}
void display(link *&ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	display(ptr->next);
	cout<<ptr->data<<" ";
}
int main()
{
	void create();
	void display(start);
	return 0;
}
