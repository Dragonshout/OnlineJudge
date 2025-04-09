#include<stdio.h>
int main()
{
	long long n = 0;
	scanf("%lld",&n);
	long long ret = 0;
	ret = ((n*(n+1))/2)-n;
	printf("%lld",ret);
	return 0;
}