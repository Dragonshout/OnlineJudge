#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int a,b,c;
}red[1024],blue[1024];
bool cmp(node a,node b)
{
	if(a.a == b.a)
	{
		if(a.b == b.b)
		{
			return a.c > b.c;
		}
		return a.b > b.b;
	}
	return a.a > b.a;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&red[i].a,&red[i].b,&red[i].c);
	}
	sort(red,red+n,cmp);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&blue[i].a,&blue[i].b,&blue[i].c);
	}
	sort(blue,blue+m,cmp);
	int rM=0,bM=0;
	for(int i = 0;i < 3;i++)
	{
		if(cmp(blue[i],red[i]))
		{
			bM++;
		}
		else
		{
			rM++;
		}
	}
	printf("%d %d\n%s",rM,bM,rM>bM?"Red":"Blue");
	return 0;
}