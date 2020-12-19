#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool DFSUtil(int u,vector<int> adj[],vector<bool> &visited,int parent)
{
	visited[u] = true;
	for(int i=0;i<adj[u].size();i++)
	{
		if(visited[adj[u][i]] == false)
		{
			if(DFSUtil(adj[u][i],adj,visited,u))
			{
				return true;
			}
		}
		
		else if(adj[u][i]!=parent)
		{
			return true;
		}
	}
	
	return false;
}

bool DFS(vector<int> adj[],int V)
{
	vector<bool> visited(V,false);
	for(int u=0;u<V;u++)
	{
		if(visited[u] == false)
		{
			if(DFSUtil(u,adj,visited,-1))
			{
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj,0,1);
	//addEdge(adj,0,2);
	addEdge(adj,0,3);
	//addEdge(adj,1,4);
	//addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	DFS(adj,V)? cout << "Graph contains cycle\n": cout << "Graph doesn't contain cycle\n";;	
	return 0;
}
