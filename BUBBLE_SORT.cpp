#include<bits/stdc++.h>

using namespace std;

void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int* arr,int n)
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				cout<<"swap = "<<arr[j]<<" "<<arr[j+1]<<endl;
				swap(&arr[j],&arr[j+1]);
			}
			else
				cout<<"no swap"<<endl;
			
		}
		
		for(int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<endl;
		cout<<"---------------------"<<endl;
	}
		
}

void improvebubblesort(int* arr,int n)
{
	bool sorted = true;
	for(int i=n-1;i>=0;i--)
	{
		sorted=false;
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				cout<<"swap = "<<arr[j]<<" "<<arr[j+1]<<endl;
				swap(&arr[j],&arr[j+1]);
				sorted = true;
			}
			else
				cout<<"no swap"<<endl;	
		}
		
		if(sorted == false)
		{
			cout<<"SORTED..!"<<endl;
			break;
		}
		for(int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<endl;
		cout<<"---------------------"<<endl;
	}
	
	
}

/*
Recursive Method for Bubble Sort
*/
void bubbleSort(int arr[], int n) 
{ 
     
    if (n == 1) 
        return; 
  
    
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
  
   
    bubbleSort(arr, n-1); 
} 


int main()
{
	int arr[] = {5,9,36,7,1,39,4,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	improvebubblesort(arr,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;	
}
