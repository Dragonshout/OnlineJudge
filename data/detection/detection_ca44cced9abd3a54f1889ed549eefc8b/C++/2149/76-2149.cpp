#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve()
{
	int n;cin>>n;
	int p=n+2+4*n+6;
	int cnt=0;
	for(int i=1;i<=13*n+19;i++)cout<<'*';
	cout<<'\n';
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=13*n+19;i++)
		{
			if(i==1||i==13*n+19)cout<<"*";
			else cout<<'.';
		}
		cout<<'\n';
	}
	for(int i=1;i<=2*n+3;i++)
	{
		for(int j=1;j<=13*n+19;j++)
		{
			if(j==1)cout<<"*";
			if(j>1&&j<=n+2)cout<<".";
			if(j>n+2&&j<=3*n+5)
			{
				if(i==1||i==2*n+3)cout<<'@';
				else 
				{
					if(j==n+3)cout<<'@';
					else cout<<".";
				}
			}
			if(j>3*n+5&&j<=4*n+6)cout<<'.';
			if(j>4*n+6&&j<=6*n+9)
			{
				if(i<n+2)
				{
					if(abs(j-p)==cnt)cout<<"@";
					else cout<<".";
				}
				else if(i==n+2)cout<<'@';
				else
				{
					if(j==4*n+7||j==6*n+9)cout<<"@";
					else cout<<".";
				}
			}
			if(j>6*n+9&&j<=7*n+10)cout<<".";
			if(j>7*n+10&&j<=9*n+13)
			{
				if(i==2*n+3)cout<<"@";
				else
				{
					if(j==7*n+11||j==9*n+13)cout<<"@";
					else cout<<".";
				}
			}
			if(j>9*n+13&&j<=10*n+14)cout<<".";
			if(j>10*n+14&&j<=12*n+17)
			{
				if(i==1||i==2*n+3)cout<<"@";
				else
				{
					if(j==10*n+15)cout<<"@";
					else cout<<".";
				}
			}
			if(j>12*n+17&&j<=13*n+18)cout<<".";
			if(j==13*n+19)cout<<"*";
		}
		cnt++;
		cout<<'\n';
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=13*n+19;i++)
		{
			if(i==1||i==13*n+19)cout<<"*";
			else cout<<'.';
		}
		cout<<'\n';
	}
	for(int i=1;i<=13*n+19;i++)cout<<'*';
	cout<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}