#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int palindrome(char* str,int s,int e)
{
	if(s==e)
		return 1;

	if(str[s]!=str[e])
		return 0;

	if (s!=e)
		palindrome(str,s+1,e-1); 
}

void swap(char* str,int n)
{
	int s = 0;
	while(s!=n/2)
	{
		char l = str[s];
		str[s] = str[n-1-s];
		str[n-1-s] = l;
		s++;
	}

}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("INVALID INPUT\n");
		exit(1);
	}
	
	int n = strlen(argv[1]);
	int s=0;

	int res = palindrome(argv[1],s,n-1);

	if(res==0)
		printf("NOT A PALINDROME\n");
	else
		printf("PALINDROME\n");

	swap(argv[1],n);

	printf("%s\n",argv[1]);

	return 0;
}
