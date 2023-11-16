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
	{
		return;
	}
	display(root->left);
	cout<<root->data;
	display(root->right);
}
Node *search(Node *root,int val)
{
	if(root==0 || root->data==val)
	{
		return root;
	}
	if(root->data<val)
	{
		cout<<"\nIn right sub-tree"<<endl;
		return search(root->right,val);
	}
	else if(root->data>val)
	{
		cout<<"\nIn left sub-tree"<<endl;
		return search(root->left,val);
	}
}
int Ltree(Node *root)
{
	if(root==0)
	{
		return 0;
	}
	int count=0;
	while(root->left!=0)
	{
		count++;
		root=root->left;
	}
	return count;
}

int main()
{
	int n,val;
	Node *root=0;
	cout<<"\nEnter the no. of elements for the tree:";
	cin>>n;
	cout<<"\nEnter the root element of the BST:";
	cin>>val;
	root=insert(root,val);
	for(int i=0;i<n-1;i++)
	{
		cout<<"\nEnter the element:";
		cin>>val;
		insert(root,val);
	}
	cout<<"\nBST created successfully!!"<<endl;
	display(root);
	cout<<"\nEnter the element to search:";
	cin>>val;
	search(root,val); 
	cout<<"\n"<<search(root,val)<<endl;
	int Tleft=Ltree(root);
	cout<<"\n"<<Tleft;
	return 0;
}
