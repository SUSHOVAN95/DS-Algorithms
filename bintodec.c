#include<stdio.h>
#include<stdlib.h>

int bintodec(int n)
{
	int dec=0;
	int base = 1;
	
	while(n!=0)
	{
		int temp = n%10;
		dec=dec+temp*base;
		base=base*2;
		n=n/10;
	}

	return dec;
}

int main(int argc, char const *argv[])
{

	if (argc<2)
	{
		printf("INVALID OUTPUT\n");
		exit(1);
	}

	int n = atoi(argv[1]);
	int val = bintodec(n);
	printf("%d\n",val);
	return 0;
}
