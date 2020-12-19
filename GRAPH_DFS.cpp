#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
}

void DFSUtil(int u,vector<int> adj[],vector<bool> &visited)
{
	visited[u] = true;
	cout<<u<<" ";
	
	int n = adj[u].size();
	for(int i=0;i<n;i++)
	{
		if(visited[adj[u][i]] == false)
		{
			DFSUtil(adj[u][i],adj,visited);
		}
	}
}

void DFS(vector<int> adj[],int V)
{
	vector<bool> visited(V,false);
	for(int u=0;u<V;u++)
	{
		if(visited[u] == false)
			DFSUtil(u,adj,visited);
	}
	
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,0,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	DFS(adj,V);	
	return 0;
}
