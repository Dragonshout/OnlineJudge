#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
void solve()
{
	int c;cin>>c;
	int n1,y1,r1,s1,f1,m1;cin>>n1>>y1>>r1>>s1>>f1>>m1;
	int n2,y2,r2,s2,f2,m2;cin>>n2>>y2>>r2>>s2>>f2>>m2;
	int sum=0;
	int p=1;
	sum+=(m1-m2)*p;
	p=60;
	sum+=(f1-f2)*p;
	p=60*60;
	sum+=(s1-s2)*p;
	p=60*60*24;
	sum+=(r1-r2)*p;
	y1-=1;
	y2-=1;
	if(y1<1)
	{
		n1-=1;
		y1=12;
	}
	if(y2<1)
	{
		n2-=1;
		y2=12;
	}
	int cnt=0;
	if(n1<n2)
	{
		cout<<"NO\n";
		return ;
	}
	int z[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=n2;i<=n1;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)z[2]=29;
		else z[2]=28;
		for(int j=1;j<=12;j++)
		{
			if(n1==n2)
			{
				if(j>y2&&j<=y1)cnt+=z[j];
			}
			else
			{
				if(i==n2)
				{
					if(j>y2)
					{
						cnt+=z[j];
					}
				}
				else if(i==n1)
				{
					if(j<=y1)
					{
						cnt+=z[j];
					}
				}
				else cnt+=z[j];
			}
		}
	}
	sum+=cnt*p;
	if(sum<0||sum>c)cout<<"NO\n";
	else cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}