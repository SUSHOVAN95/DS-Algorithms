#include<bits/stdc++.h>

using namespace std;

int no_of_paths(int m,int n)
{
	if(n==1 || m==1)
	{
		return 1;
	}

	return no_of_paths(m-1,n) + no_of_paths(m,n-1);

}

int no_of_path(int m,int n) // using dynamic programming
{
	int T[m][n]; // each cell represent no. of ways possible to reach that cell

	for (int i = 0; i < m; ++i)
	{
		T[i][0] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		T[0][i] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			T[i][j] = T[i-1][j] + T[i][j-1];
		}
	}

	return T[m-1][n-1];
}



int main()
{
	int c,r;
	cin>>r;
	cin>>c;

	cout<<no_of_paths(r,c)<<endl;
	cout<<no_of_path(r,c)<<endl;

	
	return 0;
}