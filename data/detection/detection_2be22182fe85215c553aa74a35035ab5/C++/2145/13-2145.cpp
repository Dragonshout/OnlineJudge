#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n;cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int ans=n*(n+1)/2;
	cout<<ans-n<<"\n";
	return 0;
}