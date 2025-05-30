#include<stdio.h>
long long cluc(long long n)
{
	if(n==1)
	{
		return 1;
	}
	return n+cluc(n-1);
}
int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld",cluc(n)-n);
	return 0;
}