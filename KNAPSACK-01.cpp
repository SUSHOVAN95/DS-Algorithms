#include<bits/stdc++.h>

using namespace std;


int knapsack01(int W[],int P[],int n,int c) // dynamic programming
{
	int T[n+1][c+1];

	for (int i = 0; i <=n ; i++)
	{
		T[i][0] = 0;
	}

	for (int i = 0; i <= c; i++)
	{
		T[0][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if ((W[i-1]<=j) && (T[i-1][j] < (P[i-1] + T[i-1][j-W[i-1]]) ))
			{
				T[i][j] = P[i-1] + T[i-1][j-W[i-1]];	
			}
			else
				T[i][j] = T[i-1][j];	
		}
	}
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			cout<<T[i][j]<<" ";
		}

		cout<<endl;
	}


	return T[n][c];


}

int main()
{
	int W[] = {1,2,4};
	int P[] = {10,12,28};

	int c = 6;
	int n = sizeof(P)/sizeof(int);

	cout<<knapsack01(W,P,n,c)<<endl; 
	
	return 0;
}