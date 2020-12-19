#include<bits/stdc++.h>

using namespace std;


void distinct(string str)
{
	int n = str.length();
	map<char,int> M;
	for(int  i=0;i<n;i++)
	{
		M[str[i]]++;
	}
	
	map<char,int>:: iterator it;
	for(it = M.begin();it!=M.end();it++)
	{
		cout<<it->first<<" FREQUENCY = "<<it->second<<endl;
	}
	
}
int main()
{
		string s = "aaaabbbbcccddghtttteeaaafddddiiiaawwcccgd";
		distinct(s);
		return 0;
}
