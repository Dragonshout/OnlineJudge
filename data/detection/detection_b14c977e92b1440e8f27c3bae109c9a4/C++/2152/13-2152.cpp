#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve(){
	int l,r;cin>>l>>r;
	int k;
	int ans=-1;
	if(r-l<100){
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
	}else{
		int f=0,ff=0;
		int x=l;
		while(x){
			if(x%10==9)f=1;
			if(x%10==0)ff=1;
			x/=10;
		}
		if(ff and f){
			cout<<l<<"\n";
			return ;
		}
		for(int i=l+1;i<=r;i++){
			int x=i;
			int f=0,ff=0;
			while(x){
				if(x%10==9)f=1;
				if(x%10==0)ff=1;
				x/=10;
			}
			if(ff and f){
				cout<<i<<"\n";
				return ;
			}
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