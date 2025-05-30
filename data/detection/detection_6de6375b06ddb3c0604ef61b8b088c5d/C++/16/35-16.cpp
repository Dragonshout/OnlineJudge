#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dp[3][N];
void solve()
{
    int n;cin>>n;
	string a[3];
    for(int i=1;i<=2;i++)
    {
        cin>>a[i];  a[i]=' '+a[i];
    }
    
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(a[1][i]=='R'&&a[1][i-1]=='R')dp[1][i]+=dp[1][i-1]+1;
        if(a[2][i]=='R'&&a[2][i-1]=='R')dp[2][i]+=dp[2][i-1]+1;
        if(a[1][i]=='R'&&a[2][i]=='R')
        {
            if(dp[1][i]<dp[2][i])dp[1][i]=dp[2][i]+1;
            else if(dp[2][i]<dp[1][i])dp[2][i]=dp[1][i]+1;
            else dp[2][i]=dp[1][i]=dp[2][i]+1;
        }
        res=max(max(dp[1][i],res),dp[2][i]);
    }
    cout<<res<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}