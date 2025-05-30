#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e5+5;
int l,r;
void solve()
{
	cin>>l>>r;
	int ans=0,res=-1;
	for(int i=l;i<=r;i++)
	{
		int t=i;
		int mx=0,mn=9;
		while(t)
		{
			mx=max(mx,t%10),mn=min(mn,t%10);
			t/=10;
		}
		if(mx-mn>res) res=mx-mn,ans=i;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}