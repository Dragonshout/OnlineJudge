#include<stdio.h> 
int main()
{
	int n;int a[100];
	int t;
	scanf("%d",&n);
	int i;
	for(i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&t);
	
	int va = 0;
	for(i = 0;i<n;i++)
	{
		int b = t-a[i];
		if(b==0)
		va += 10;
		else if(b>0)
		va -= b;
		else
		va -= -b;
	}
	printf("%d\n",va);
	if(va>0)
	printf("Happy");
	return 0;
}