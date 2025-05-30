#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve()
{
	int l,r;cin>>l>>r;
	if(r-l>=100)
	{
		int h=-1;
		int ans=-1;
		for(int i=l;i<=l+100;i++)
		{
			int mn=1e9,mx=-1;
			int f=i;
			while(f)
			{
				int z=f%10;
				f/=10;
				mn=min(z,mn);
				mx=max(z,mx);
			}
			if(mx-mn>h)
			{
				h=mx-mn;
				ans=i;
			}
		}
		cout<<ans<<'\n';
	}
	else
	{
		int h=-1;
		int ans=-1;
		for(int i=l;i<=r;i++)
		{
			int mn=1e9,mx=-1;
			int f=i;
			while(f)
			{
				int z=f%10;
				f/=10;
				mn=min(z,mn);
				mx=max(z,mx);
			}
			if(mx-mn>h)
			{
				h=mx-mn;
				ans=i;
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}