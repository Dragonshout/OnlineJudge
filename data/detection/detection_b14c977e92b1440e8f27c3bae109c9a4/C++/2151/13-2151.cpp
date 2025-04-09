#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
	string s;cin>>s;
	string a=s+"0000",b=s+"000";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());b+='0';
	int f=0;
	for(int i=0;i<b.size();i++){
		int x=a[i]-'0';
		int y=b[i]-'0';
		int ans=x+y+f;
		if(ans==1){
			a[i]='1';
			f=0;
		}else if(ans==2){
			a[i]='0';
			f=1;
		}else if(ans==3){
			a[i]=='1';
			f=1;
		}
	}
	if(f)a+='1';
	f=0;reverse(s.begin(),s.end());
	s+="0000";
	for(int i=0;i<a.size();i++){
		int x=a[i]-'0';
		int y=s[i]-'0';
		int ans=x+y+f;
		if(ans==1){
			a[i]='1';
			f=0;
		}else if(ans==2){
			a[i]='0';
			f=1;
		}else if(ans==3){
			a[i]=='1';
			f=1;
		}
	}
	if(f)a+='1';
	reverse(a.begin(),a.end());
	cout<<a<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;//cin>>t;
	while(t--) solve();
	return 0;
}