#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
void solve()
{
	int n;cin>>n;
	int p=(n+1)*n/2;
	int q=n;
	cout<<p-q<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}