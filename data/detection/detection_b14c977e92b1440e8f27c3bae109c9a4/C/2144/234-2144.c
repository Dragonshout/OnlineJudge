#include <stdio.h>
#include <math.h>
int main()
{
	int a[100];
	int n;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int goal;
	scanf("%d",&goal);
	int sum;
	int d;
	sum=0;
	for(i=0;i<n;i++)
	{d=fabs(a[i]-goal);
	if(d==0)
	sum+=10;
	else
	sum-=d;
	}
	printf("%d\n",sum);
	if(sum>0)
	printf("Happy");
	return 0;
}