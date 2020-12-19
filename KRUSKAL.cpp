#include<bits/stdc++.h>

using namespace std;

int findMV(int* distance,bool* visited,int n)
{
	int minVertex = -1;
	for (int i = 0; i < n; i++)
	{
		if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex]))
		{
			minVertex = i;
		}
	}

	return minVertex;
}


void dijakstra(int** V,int n)
{
	int* distance = new int[n];
	bool* visited = new bool[n];

	for (int i = 0; i < n; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0;

	for (int i = 0; i < n-1; i++)
	{
		int minVertex = findMV(distance,visited,n);
		visited[minVertex] = true;
		
		for (int j = 0; j < n; j++)
		{
			if (V[minVertex][j]!=0 && !visited[j])
			{
				int dist = distance[minVertex] + V[minVertex][j];
				if (dist<distance[j])
				{
					distance[j] = dist;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout<<i<<" "<<distance[i]<<endl;
	}

	delete [] visited;
	delete [] distance; 
}


int main()
{
	cout<<"ENTER THE NUMBER OF VERTEX AND EDGES"<<endl;
	int n,e;
	cin>>n>>e;
	int**  V = new int*[n];

	for (int i = 0; i < n; i++)
	{
		V[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			V[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int s,d,w;
		cout<<"ENTER SOURCE DEST AND WEIGHT"<<endl;
		cin>>s>>d>>w;

		V[s][d] = w;
		V[d][s] = w;
	}

	dijakstra(V,n);
	
	return 0;
}
