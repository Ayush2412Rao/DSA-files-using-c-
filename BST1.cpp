#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};

Node *create(int val)
{
	Node *newnode=new Node;
	newnode->data=val;
	newnode->left=0;
	newnode->right=0;
	return newnode;
} 

Node *insert(Node *root,int val)
{
	if(root==0)
	{
		return create(val);
	}
	else if(val<root->data)
	{
		root->left=insert(root->left,val);
	}
	else if(val>root->data)
	{
		root->right=insert(root->right,val);
	}
	return root;
}

void display(Node *root)
{
	if(root==0)
		return;
	display(root->left);
	cout<<" "<<root->data;
	display(root->right);
	
}

Node *search(Node *root,int no)
{
	if(root==0 ||root->data==no)
	{
		return root;
	}
	else if(root->data<no)
	{
		return search(root->right,no);
	}
	else
	{
		return search(root->left,no);
	}
}

int main()
{
	Node*root;
	int no,n;
	root=0;
	cout<<"\nEnter the number of elements you want to insert in the BST-----"<<endl;
	cin>>n;
	cout<<"\nEnter the top root value:"<<endl;
	cin>>no;
	root=insert(root,no);
	for(int i=0;i<n-1;i++)
	{
		cout<<"\nEnter the element:"<<endl;
		cin>>no;
		root=insert(root,no);
	}
	cout<<"\nBST created successfully!!"<<endl;
	display(root);
	cout<<"\nEnter the number to search:";
	cin>>no;
	if(search(root,no)==0)
	{
		cout<<"\nNot found";
	}
	else
	{
		cout<<"\nFound";
	}
	return 0;
}
