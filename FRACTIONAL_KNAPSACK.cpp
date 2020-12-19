#include<bits/stdc++.h>

using namespace std;

typedef struct Item
{
	int value;
	int weight;
	
}I;

bool comp(I x,I y)
{
	double r1 = (double)(x.value/x.weight);
	double r2 = (double)(y.value/y.weight);

	return r1>r2;
}

double fracknsack(I arr[],int W,int n)
{

	for (int i = 0; i < n; i++)
	{
		int v,w;
		cout<<"{"<<arr[i].value<<","<<arr[i].weight<<"}"<<",";
	}
	
	sort(arr,arr+n,comp);
	
	cout<<endl;
	for (int i = 0; i < n; i++)
	{
		int v,w;
		cout<<"{"<<arr[i].value<<","<<arr[i].weight<<"}"<<",";
	}

	float valsum = 0;
	int curwt = 0;

	for (int i = 0; i < n; i++)
	{
		if (curwt+arr[i].weight <= W)
		{
			curwt += arr[i].weight;
			valsum += arr[i].value;
		}
		else
		{
			int w = W - curwt;
	
		
			valsum += arr[i].value*(double)w/arr[i].weight;
			
			break;
		}
	}

	return valsum;
}

int main()
{
	
	int W;
	cout<<"MAXIMUM SIZE OF THE KNAPSACK = ";
	cin>>W;

	cout<<"ENTER THE NUMBER OF OBJECTS"<<endl;
	int n;
	cin>>n;

	I arr[n];

	for (int i = 0; i < n; i++)
	{
		int v,w;

		cout<<"VALUE = ";cin>>v;arr[i].value = v;
		cout<<"WEIGHT = ";cin>>w;arr[i].weight = w;
	}

	cout<<endl<<"RESULT = "<<fracknsack(arr,W,n);

}
