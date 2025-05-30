#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	while(n!=1)
	{
		if(n%2!=0)
		n=3*n+1;
      n/=2;i++;
	}
	printf("%d",i);
	return 0;
}