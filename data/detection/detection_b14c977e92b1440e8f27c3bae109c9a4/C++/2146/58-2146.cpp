#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ok(int x){
	vector<int> v;
	while(x){
		v.push_back(x%10);
		x/=10;
	}
	sort(v.begin(),v.end());
	int len=v.size();
	int res=v[len-1]-v[0];
	return res;
}
void work(){
	int l,r;
	cin>>l>>r;
	int maxn=-1;
	int ans=0;
	for(int i=l;i<=r;i++){
		if(ok(i)>maxn){
			ans=i;
			maxn=ok(i);	
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t=1;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}