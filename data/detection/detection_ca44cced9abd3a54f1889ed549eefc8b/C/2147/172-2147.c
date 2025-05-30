#include<stdio.h>
typedef struct team
{
	int a;
	int b;
	int c;
} team;
int Fight(team a,team b)
{
	if(a.a>b.a)
	{
		return 1;
	}
	else if(a.a<b.a)
	{
		return 0;
	}
	if(a.b>b.b)
	{
		return 1;
	}
	else if(a.b<b.b)
	{
		return 0;
	}
	if(a.c>b.c)
	{
		return 1;
	}
	else if(a.c<b.c)
	{
		return 0;
	}
	return 1;
}
int cmp(const void* pa,const void* pb)
{
	if(Fight(*((team*)pa),*((team*)pb))==1)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int acount = 0;
	scanf("%d",&acount);
	team agroup[1002] = {0};
	for(int i = 0;i<acount;i++)
	{
		scanf("%d %d %d",&agroup[i].a,&agroup[i].b,&agroup[i].c);
	}
	team ateams[3] = {0};
	for(int i = acount - 1;i>=0;i--)
	{
		for(int j = 0;j<i;j++)
		{
			if(cmp(&agroup[j],&agroup[j + 1])==1)
			{
				team tempt = agroup[j];
				agroup[j] = agroup[j + 1];
				agroup[j + 1] = tempt;
			}
		}
	}
	for(int i =0;i<3;i++)
	{
		ateams[i] = agroup[i];
	}
	
	
	int bcount = 0;
	scanf("%d",&bcount);
	team bgroup[1002] = {0};
	for(int i = 0;i<bcount;i++)
	{
		scanf("%d %d %d",&bgroup[i].a,&bgroup[i].b,&bgroup[i].c);
	}
	team bteams[3] = {0};
	for(int i = bcount - 1;i>=0;i--)
	{
		for(int j = 0;j<i;j++)
		{
			if(cmp(&bgroup[j],&bgroup[j + 1])==1)
			{
				team tempt = bgroup[j];
				bgroup[j] = bgroup[j + 1];
				bgroup[j + 1] = tempt;
			}
		}
	}
	for(int i =0;i<3;i++)
	{
		bteams[i] = bgroup[i];
	}
	
	int victory[3] = {0};
	for(int i =0;i<3;i++)
	{
		if(Fight(ateams[i],bteams[i])==1)
		{
			victory[i] = 1;
		}
	}
	int av = 0;
	int bv = 0;
	for(int i =0;i<3;i++)
	{
		if(victory[i]==1)
		{
			av++;
		}
		else
		{
			bv++;
		}
	}
	printf("%d %d\n",av,bv);
	if(av>bv)
	{
		printf("Red");
	}
	else
	{
		printf("Blue");
	}
	return 0;
}