#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int nums[128];
int main()
{
	int n,key;
	int luck = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&nums[i]);
	}
	scanf("%d",&key);
	for(int i=1;i<=n;i++)
	{
		if(nums[i]==key)
		{
			luck += 10;
		}
		else
		{
			luck -= abs(nums[i] - key);
		}
	}
	printf("%d",luck);
	if(luck>0)
	{
		printf("\nHappy");
	}
	return 0;
}