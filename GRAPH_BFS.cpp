#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> V[],int u,int v)
{
	V[u].push_back(v);
}

void BFSUtil(int u,vector<int> adj[],vector<bool> &visited)
{
	queue<int> Q;
	visited[u] = true;
	Q.push(u);

	while(!Q.empty())
	{
		
		int n = Q.size();
		for (int i = 0; i<n; i++)
		{
			int s = Q.front();
			cout<<s<<" ";
			Q.pop();

			int m = adj[s].size();
			
			for(int j=0;j<m;j++)
			{
				if (!visited[adj[s][j]])
				{
					visited[adj[s][j]] = true;
					Q.push(adj[s][j]);
				}
			}
		}

		cout<<endl;		
	}
}


void BFS(vector<int> adj[],int V)
{

	vector<bool> visited(V,false);
	for(int u=0;u<V;u++)
	{
		if(visited[u] == false)
		{
			cout<<"ENTERING TO BFS..."<<endl;
			BFSUtil(u,adj,visited);
		}
	}
	
}





int main()
{
	int V = 5;
	std::vector<int> adj[V];

	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,0,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,2,4);
	BFS(adj,V);


}
