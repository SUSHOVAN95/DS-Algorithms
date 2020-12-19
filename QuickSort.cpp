#include<bits/stdc++.h>

using namespace std;

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[],int l,int h)
{
	int pivot = arr[h];
	int i = l-1;

	for (int j = l; j < h; j++)
	{
		if (arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}

	swap(&arr[i+1],&arr[h]);
	return (i+1);
}


void Quicksort(int arr[],int l,int h)
{
	if (l<h)
	{
		int pi = partition(arr,l,h);

		Quicksort(arr,l,pi-1);
		Quicksort(arr,pi+1,h);
	}
}


int main()
{
	cout<<"ENTER THE LENGTH OF THE ARRAY"<<endl;

	int n;
	cin>>n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	Quicksort(arr,0,n-1);

	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;


}
