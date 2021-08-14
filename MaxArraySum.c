
int maxSubArraySum(int A[], int n) 
{ 
   if(n==-1)
   {
       return -500;
   }
   
   return max(maxSubArraySum(A,n-1),max(maxSubArraySum(A,n-1)+A[n],A[n]));
}
