#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve(){
	int l,r;cin>>l>>r;
	int k;
	int ans=-1;
	for(int i=l;i<=r;i++){
		int x=i;
		int ma=0;
		int mi=9;
		while(x){
			ma=max(ma,x%10);
			mi=min(mi,x%10);
			x/=10;
		}
		if(ma-mi>ans){
			ans=ma-mi;
			k=i;
		}
	}
	cout<<k<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--) solve();
	return 0;
}