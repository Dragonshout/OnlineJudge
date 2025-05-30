#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n;cin>>n;
	int x=(sqrt(8*n+1)-1)/2;
	while(x*x+x<2*n)x++;
	cout<<x<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--) solve();
	return 0;
}