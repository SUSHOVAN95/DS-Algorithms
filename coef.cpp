#include<bits/stdc++.h>

using namespace std;

int coef(int ,int );
int coefDP(int ,int );


int main()
{

	int n,k;
	cout<<"ENTER THE NUMBER n = "<<endl;
	cin>>n;

	cout<<"ENTER THE NUMBER k = "<<endl;
	cin>>k;


	int num = coef(n,k);

	cout<< "COEFFICIENT = "<<num<<endl;

	num = coefDP(n,k);

	cout<< "COEFFICIENT(DP) = "<<num<<endl;



	return 0;
}

int coef(int n,int k)
{
	if (k>n)
	{
		return 0;
	}
	if(k == 0 || k == n) //base case nc0 = ncn = 1
		return 1;

	return coef(n-1,k-1) + coef(n-1,k);
}

// bottom up DP approach as it has overlapping subproblem property

int coefDP(int n,int k)
{
	if (k>n)
	{
		return 0;
	}
	int C[n+1][k+1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i,k) ; j++)
		{
			if(j == 0 || j == i)
				C[i][j] = 1;

			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

	return C[n][k];
}

