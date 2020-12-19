#include<bits/stdc++.h>

using namespace std;


int prece(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	
	else return -1;
}

string intopost(string s)
{
	string r;
	stack<char> S;

	S.push('$');

	for (int i = 0; i < s.length(); i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			r.push_back(s[i]);
		}
		else if (s[i]== '(')
		{
			S.push(s[i]);
		}
		else if(s[i]==')')
		{
			while(S.top()!='$' && S.top()!='(')
			{
				char t = S.top();
				S.pop();
				r.push_back(t);
			}
			if (S.top() == '(')
			{
				S.pop();
			}
		}
		else
		{
			while(S.top()!='$' && prece(s[i]) <= prece(S.top()))
			{
				char t = S.top();
				S.pop();
				r.push_back(t);
			}
			S.push(s[i]);
		}
		
	}

	while(S.top()!='$')
	{
		char t = S.top();
		S.pop();
		r.push_back(t);
	}

	return r;
}


string intopre(string s)
{
	string V;
	for (int i = s.length()-1; i >=0 ;i--)
	{
		if(s[i]=='(')
		{
			V.push_back(')');
		}

		if(s[i]==')')
		{
			V.push_back('(');
		}

		else
			V.push_back(s[i]);
	}

	string t = intopost(V);
	reverse(t.begin(), t.end());

	return t;
}

int main()
{
	string s;
	
	cout<<"ENTER THE INFIX EXPRESSION\n";
	cin>>s;

	s = intopre(s);

	cout<<"EQUIVALENT POSTFIX EXPRESSION:\n";
	cout<<s<<endl;
	return 0;
}
