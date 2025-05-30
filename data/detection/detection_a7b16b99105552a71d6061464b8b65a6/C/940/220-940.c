#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int flag=0;
	int result=0;
	while(flag==0)
	{
		if(n%2==0)
		{
			n=n/2;
			result++;
		}
		else
		{
			n=(3*n+1)/2;
			result++;
		}
		if(n==1)
		{
			flag=1;
			printf("%d",result);
		}
	}
	return 0;
}