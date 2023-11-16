
//Program for binary tree
#include<iostream>
using namespace std;
 
 struct Node
 {
 	int data;
 	Node *left,*right;
 };
 
 Node *create()
 {
 	int x;
 	Node *newnode;
 	newnode=new Node;
 	cout<<"\nEnter the element(-1 for no node)"<<endl;
 	cin>>x;
 	if(x==-1)
 	{
 		return 0;
	}
	newnode->data=x;
	cout<<"\nEnter the left element of "<<x<<endl;
	newnode->left=create();
	cout<<"\nEnter the right element of "<<x<<endl;
	newnode->right=create();
	return newnode;
 }
 
 void preorder(Node *root)
 {
 	if(root==0)
 	{
 		return;
	}
	else
	{
		cout<<" "<<root->data<<endl;
		preorder(root->left);
		preorder(root->right);
	}
 }
 void postorder(Node *root)
 {
 	if(root==0)
 	{
 		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<" "<<root->data<<endl;
	}
 }
 void inorder(Node *root)
 {
 	if(root==0)
 	{
 		return;
	}
	else
	{
		inorder(root->left);
		cout<<" "<<root->data<<endl;
		inorder(root->right);
	}
 }
 
 
 int main()
 {
 	Node *root;
 	root=0;
 	cout<<"\nHere we are creating a Binary Tree--------"<<endl;
 	root=create();
 	cout<<"\nBinary Tree created succesfully!!"<<endl;
 	
 	cout<<"\nPre-Order traversal----"<<endl;
 	preorder(root);
 	cout<<"\nPost-Order traversal----"<<endl;
 	postorder(root);
 	cout<<"\nIn-Order traversal----"<<endl;
 	inorder(root);
 	return 0;
 }
