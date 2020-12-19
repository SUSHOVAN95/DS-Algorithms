#include<stdio.h>
#include<stdlib.h>

void palindrome(int n)
{
	int val = n;
	int num=0;
	while(n)
	{
		int temp=n%10;
		num = num*10+temp;
		n=n/10;
	}

	(num==val)?printf("PALINDROME\n"):printf("NOT A PALINDROME\n");
}

int main(int argc, char *argv[])
{
	if (argc<2)
	{
		printf("INVALID INPUT\n");
		exit(1);
	}

	int n = atoi(argv[1]);
	palindrome(n);
	
	return 0;
}