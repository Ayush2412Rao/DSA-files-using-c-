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
	int start,stack[n],dfs[n],status[n],top=-1,k=0;//modified
	for(i=0;i<n;i++)
	{
		status[i]=0;
	}
	cout<<"From which vertex you want to start traversing: "<<endl;
	cin>>start;	
	top=0;//modified
	stack[top]=start;//modified
	status[start]=1;
	while(top!=-1)//modified
	{
		int w=stack[top];
		top--;
		dfs[k++]=w;
		status[w]=2;
		for(int a=0;a<n;a++)
		{
			if(adj[w][a]==1 && status[a]==0)
			{
				stack[++top]=a;
				status[a]=1;
			}
		}
	}
	
	cout<<"\nThe DFS is:"<<endl;
	for(i=0;i<k;i++)
	{
		cout<<dfs[i]<<" ";
	}
	return 0;
}
