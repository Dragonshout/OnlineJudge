#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e5+5;
int n;
int a[N];
void solve()
{
	cin>>n;
	int ans=n*(n+1)/2-n;
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}