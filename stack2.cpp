#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};
Node *newnode,*head=0,*temp,*prevnode;

int count = 0;

void push(int data) 
{
     if(head==0)
    {
        newnode =new Node;
        newnode->next = 0;
        newnode->data= data;
    }
    else
    {
    	temp=head;
    	while(temp->next!=0)
    	{
    		temp=temp->next;
		}
        newnode =new Node;
        newnode->data=data;
        newnode->next=0;
        temp->next=newnode;
        temp=temp->next;
    }
    count++;
    printf("Node is Inserted\n\n");
}

int pop() 
{
    temp = head;
 
    if (head==0)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
    	prevnode=temp;
    	while(temp->next!=0)
    	{
    		temp=temp->next;
    		prevnode=temp;
		}
		
		temp=temp->next;
		prevnode->next=0;
		delete temp;     
    }
    
}

void display()
{
    
 
    if (head == 0)
    {
        printf("\nStack Underflow\n");
        return;
    }
    
    else
    {
    	temp=head;
    	cout<<"\nStack is---------\n";
    	while(temp!=0)
    	{
    		cout<<temp->data<<"\n"<<endl;
    		temp=temp->next;
		}
	}

}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}


