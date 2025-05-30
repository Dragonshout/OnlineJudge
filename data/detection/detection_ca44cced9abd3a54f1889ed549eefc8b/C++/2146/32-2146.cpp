#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
//#define int long long
void solve(){
	int l,r;
	cin>>l>>r;
	int ans=0, num=l;
	int i;
	for (i=l;i<=r;i++){
		int tmp=i;
		int maxn=-1,minn=10;
		while (tmp!=0){
			int x=tmp%10;
			maxn=max(maxn,x);
			minn=min(minn,x);
			tmp/=10;
		}
		if (ans<maxn-minn){
			ans=maxn-minn;
			num=i;
		}
		if (ans==9){
			break;
		}
	}
	cout<<num<<endl;
}
int main(){
	int T=1;
	cin>>T;
	while (	T--){
		solve();
	}
}