/****************************************
Merging two linked list
************************************/
#include <iostream>
#include<cstdlib>
using namespace std;
struct link
{
int data;
struct link *next;
};
struct link *start1=NULL;
struct link *start2=NULL;
struct link *node;
struct link *current;
struct link *mergeStart = NULL;
struct link *mergeCurrent = NULL;

void create(struct link *&start)
{
int n;
cout<<"how many nodes u want to create ";
cin>>n;
cout<<"Enter all elements ";
for(int i=0;i<n;i++)
{
node=((struct link *)malloc(sizeof(struct link)));
cin>>node->data;
node->next=NULL;
if(start==NULL)
{
start=node;
current=node;
}
else
{
current->next=node;
current=node;
}
}
}
void display(struct link *&start)
{
struct link *ptr=start;
while(ptr!=NULL)
{
cout<<ptr->data << " ";
ptr=ptr->next;
}
cout << endl;
}

void merge(struct link *&s1, struct link *&s2)
{
struct link *node;
while(s1 != NULL && s2 != NULL)
{
node = (struct link *)malloc(sizeof(struct link));
if(s1->data < s2->data)
{
node -> data = s1 -> data;
s1 = s1 -> next;
}
else
{
node -> data = s2 -> data;
s2 = s2 -> next;
}
node -> next = NULL;
if(mergeStart == NULL)
{
mergeStart = node;
mergeCurrent = node;
}
else
{
mergeCurrent -> next = node;
mergeCurrent = node;
}
}
while(s1 != NULL)
{
node = (struct link *)malloc(sizeof(struct link));
node -> data = s1 ->data;
mergeCurrent -> next = node;
mergeCurrent = node;
s1 = s1 -> next;
}
while(s2 != NULL)
{
node = (struct link *)malloc(sizeof(struct link));
node -> data = s2 ->data;
mergeCurrent -> next = node;
mergeCurrent = node;
s2 = s2 -> next;
}
}
int main()
{

cout<<"Enter first LinkedList"<<endl;
create(start1);
cout<<"Enter second LinkedList"<<endl;
create(start2);
cout<<"Elements of linked list one: "<<endl;
display(start1);
cout<<"Elements of linked list two: "<<endl;
display(start2);
merge(start1, start2);
display(mergeStart);
return 0;
}
