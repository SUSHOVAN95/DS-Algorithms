#include<iostream> 
#include<climits> 
using namespace std;

int maxSubArraySum(int a[], int n) 
{ 
   int M = a[0];
   int K = a[0]; 
   int i;
   for (i = 1; i < n; i++) 
   { 
        K = max(a[i],K+a[i]); // for storing the previous max;
        M = max(M,K); // storing the actual max sum 
   } 
   return M;
} 

int maxSubArraySum(int a[], int n) 
{ 
   int M[n]; 
   M[0] = a[0];
   int K = a[0];
  
   for (int i = 1; i < n; i++) 
   { 
	K = max(a[i],K+a[i]);
        M[i] = max(M[i-1],K); 
   } 
   return M[n-1];
} 

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() 
{ 
	int a[] = {-2, -3, -4, -1, -2}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	cout<< "Maximum contiguous sum is " << max_sum; 
	return 0; 
}
