#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	ll ans=0;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	int num;
	cin>>num;
	for(int i=0;i<n;i++){
		if(v[i]==num)ans+=10;
		else ans-=abs(num-v[i]);
	}
	cout<<ans<<endl;
	if(ans>0)cout<<"Happy"<<endl;
	return 0;
}