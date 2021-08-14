#include<iostream> 
#include<climits> 
using namespace std;

int maxSubArraySum(int A[], int n) 
{ 
   if(n==-1)
   {
       return -500;
   }
   
   return max(maxSubArraySum(A,n-1),max(maxSubArraySum(A,n-1)+A[n],A[n]));
}

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

int main() 
{ 
	int a[] = {-2, -3, -4, -1, -2}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	cout<< "Maximum contiguous sum is " << max_sum; 
	return 0; 
}
