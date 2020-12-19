#include<bits/stdc++.h>

using namespace std;

void armstrong(int n)
{
	int temp = n;
	int t=0;

	while(temp!=0)
	{
		temp = temp/10;
		t++;
	}

	temp = n;
	int sum = 0;

	while(temp!=0)
	{
		int dig = temp%10;
		sum = sum + pow(dig,t);
		temp = temp/10;
	}

	if(sum==n)
		cout<<"IT IS AN ARMSTRONG NUMBER"<<endl;
	else
		cout<<"IT IS NOT AN ARMSTRONG NUMBER"<<endl;
}

int main()
{
	cout<<"ENTER A NUMBER"<<endl;
	int n;
	cin>>n;

	armstrong(n);
}
