#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int Lucks[200000];
int main()
{
	int n;
	scanf("%d",&n);
	memset(Lucks,-1,sizeof(Lucks));
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int Max = -1,Maxi;
		for(int j=l;j<=r;j++)
		{
			if(Lucks[j]==-1)
			{
				char num[16];
				memset(num,0,sizeof(num));
				sprintf(num,"%d",j);
				int len = strlen(num);
				sort(num,num+len);
				Lucks[j] = num[len-1] - num[0];
			}
			if(Lucks[j]>Max)
			{
				Max = Lucks[j];
				Maxi = j;
			}
		}
		printf("%d\n",Maxi);
	}
	return 0;
}