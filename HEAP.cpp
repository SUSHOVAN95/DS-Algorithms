#include <bits/stdc++.h>

using namespace std;

void maxheapify(int *arr,int n, int i)
{
	int l,r;

	l = 2*i + 1;
	r = 2*i + 2;

	int largest = i;

	if (l<n && arr[l]>arr[i])
	{
		largest = l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest = r;
	}

	if (largest!=i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		maxheapify(arr,n,largest);
	}

}

void buildHeap(int *arr,int n)
{
    int p = ((floor(n/2))-1) ;
    for(int i=p;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }
    
}

void HeapSort(int *arr,int n)
{
    buildHeap(arr,n);
    
    for(int i=n-1;i>=0;i--)
    {
        int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		
        maxheapify(arr,i,0);
    }
    
}

int main()
{
	int arr[] = {4,8,3,9,7,2,6,1};

	int n = sizeof(arr)/sizeof(int);

	//maxheapify(arr,n,0);

	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	std::cout << std::endl;
	
	//buildHeap(arr,n);
	
	HeapSort(arr,n);
	
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}

}