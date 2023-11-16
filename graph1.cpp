#include<iostream>
using namespace std;
int main()
{
	int n,edges,i,j;
	cout<<"Enter the no. of vertices and edges: ";
	cin>>n>>edges;
	int adj[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			adj[i][j]=0;
		}
	}
	int source_vertex,dest_vertex;
	cout<<"Enter the source vertex and destination vertex of all edges: ";
	for(i=0;i<edges;i++)
	{
		cin>>source_vertex>>dest_vertex;
		adj[source_vertex][dest_vertex]=1;
	}
	cout<<"Adjacency matrix is: "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	int start,queue[n],bfs[n],status[n],front=-1,rear=-1,k=0;
	for(i=0;i<n;i++)
	{
		status[i]=0;
	}
	cout<<"From which vertex you want to start traversing: "<<endl;
	cin>>start;	
	front=rear=0;
	queue[rear]=start;
	status[start]=1;
	while(front!=-1)
	{
		int w=queue[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front++;
		}
		bfs[k++]=w;
		status[w]=2;
		for(int a=0;a<n;a++)
		{
			if(adj[w][a]==1 && status[a]==0)
			{
				queue[++rear]=a;
				if(front==-1)
				{
					front=0;
				}
				status[a]=1;
			}
		}
	}
	
	cout<<"\nThe BFS is:"<<endl;
	for(i=0;i<k;i++)
	{
		cout<<bfs[i]<<" ";
	}
	return 0;
}
