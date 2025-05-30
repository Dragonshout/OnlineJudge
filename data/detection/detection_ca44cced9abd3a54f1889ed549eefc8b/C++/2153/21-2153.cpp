#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e5+5;
int n;
void solve()
{
	cin>>n;
	int ans=sqrt(2*n);
	while(ans*(ans+1)/2<n) ans++;
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