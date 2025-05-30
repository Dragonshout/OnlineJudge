#include<bits/stdc++.h>
//#define int long long
#define all(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
using namespace std;
using i64=long long;
typedef pair<int,int> pii;
const int N=1e6+5;
int n;
string s[5];
int dp[5][N];
void solve()
{
	cin>>n;
	cin>>s[0]>>s[1];
    s[0]='W'+s[0]+'W';
    s[1]='W'+s[1]+'W';
	for(int i=1;i<=n;i++)
	{
		if(s[0][i]=='R') dp[0][i]=dp[0][i-1]+1;
		if(s[1][i]=='R') dp[1][i]=dp[1][i-1]+1;
		if(s[0][i]=='R'&&s[1][i]=='R')
		{
			int t1=dp[0][i],t2=dp[1][i];
			dp[0][i]=max(dp[0][i],t2+1);
			dp[1][i]=max(dp[1][i],t1+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,max(dp[0][i]-1,dp[1][i]-1));
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}