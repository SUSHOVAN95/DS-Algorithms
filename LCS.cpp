#include<bits/stdc++.h>

using namespace std;

int M[10][10];

/*
int LCS_Recursion(string X, string Y, int m,int n) //--> TC = O(2**n)
{
	if(m==0 || n==0) // base condition if any of the string is empty
	{
	    return 0;
	}
	
	else if(X[m-1] == Y[n-1])
	{
	    return 1 + LCS(X,Y,m-1,n-1);
	}
	
	else
	{
	    return max(LCS(X,Y,m-1,n),LCS(X,Y,m,n-1));
	}
}
*/
/*
for j ← 0 to n do
    for i ← 0 to m do
        if i = 0 or j = 0 then
            D[i, j] ← 1
        else
            D[i, j] ← 0
            if ai  = bj  then
                D[i, j] ← D[i − 1, j − 1]
            else if L[i − 1, j] = L[i, j] then
                D[i, j] ← D[i, j] + D[i − 1, j]
            endif
            if L[i, j − 1] = L[i, j] then
                D[i, j] ← D[i, j] + D[i, j − 1]
            endif
            if L[i − 1, j − 1] = L[i, j] then
                D[i, j] ← D[i, j] − D[i − 1, j − 1]
            endif
        end if
    endfor
endfor
*/

int countLCS(string X,string Y,int m,int n)
{
	int D[m+1][n+1];

	for (int i = 0; i <=m ; i++)
	{
		for (int j = 0; j <=n ; j++)
		{
			if (i == 0 || j==0)
			{
				D[i][j] = 1; 
			}

			else
			{
				D[i][j] = 0;
				if (X[i-1] == Y[j-1])
				{
					D[i][j] = D[i-1][j-1];
				}
				else if(M[i-1][j] == M[i][j] )
				{
					D[i][j] = D[i][j] + D[i-1][j];
				}
				if (M[i][j-1] == M[i][j])
				{
					D[i][j] = D[i][j] + D[i][j-1];	
				}
				if (M[i-1][j-1] == M[i][j])
				{
					D[i][j] = D[i][j] - D[i-1][j-1];	
				}
			}
		}
	}


	return D[m][n];

}

int LCS(string X, string Y, int m,int n) // bottom-up Tabular DP --> TC = O(m*n)
{
	for (int i = 0; i <= m; ++i)
	{
		M[i][0] = 0;
	}
	
	for (int i = 0; i <= n; ++i)
	{
		M[0][i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; ++j)
		{
			if(X[i-1] == Y[j-1])
				M[i][j] = 1 + M[i-1][j-1];
			else
				M[i][j] = max(M[i-1][j],M[i][j-1]);
		}
	}

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout<<M[i][j]<<" ";
		}

		cout<<endl;
	}

	int count = countLCS(X,Y,m,n);
	cout<<count<<endl;

	return M[m][n];
}


int main()
{
	string X = "qpqrr";
	string Y = "pqprqrp";
	int m = X.length();
	int n = Y.length();
	
	cout<<m<<" "<<n<<endl;


	cout<<LCS(X,Y,m,n);

}
