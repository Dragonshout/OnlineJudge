#include <bits/stdc++.h>
using namespace std;
//define int long long
void solve(){
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	int ans=0;
	int t;
	cin>>t;
	for (int i=0;i<n;i++){
		if (a[i]==t) ans+=10;
		else ans-=abs(a[i]-t);
	}
	cout<<ans<<endl;
	if (ans>0) cout<<"Happy"<<endl;
}
int main(){
	int T=1;
//	cin>>T;
	while (	T--){
		solve();
	}
}