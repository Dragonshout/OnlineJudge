#include<bits/stdc++.h>
#define int long long
using namespace std;
int suan(int n,int y,int r,int s,int f,int m)
{
	int miao=0;
	int runnian=(n-1)/4-(n-1)/100+(n-1)/400;
	int burunnian=n-1-runnian;
	int bol=0;
	if(n%4==0&&n%100!=0||n%400==0)bol=1;
	int day=0;
	for(int i=1;i<y;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)day+=31;
		else if(i==2&&bol==1)day+=29;
		else if(i==2&&bol==0)day+=28;
		else day+=30;
	}
	day+=r-1;
	miao=runnian*31622400+burunnian*31536000+day*86400+3600*(s-1)+60*(f-1)+m;
	return miao;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int c;
		cin>>c;
		int n1,y1,r1,s1,f1,m1;
		int n2,y2,r2,s2,f2,m2;
		cin>>n1>>y1>>r1>>s1>>f1>>m1;
		cin>>n2>>y2>>r2>>s2>>f2>>m2;
		int miao1=suan(n1,y1,r1,s1,f1,m1);
		int miao2=suan(n2,y2,r2,s2,f2,m2);
		if(miao2>miao1)
		{
			cout<<"NO"<<endl;
			
		}
		else if(miao1-miao2>c)
		{
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	
	
}