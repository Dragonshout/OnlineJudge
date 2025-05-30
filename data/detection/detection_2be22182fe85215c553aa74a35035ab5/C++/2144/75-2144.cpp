#include<bits/stdc++.h>
#define int long long
#define loop(n) for(int i=0;i<n;i++)
#define Loop(n) for(int i=1;i<=n;i++)
#define men(f,x) menset(f,x,sizeof(f));
using namespace std;
signed main(){
	int n;cin>>n;
	int a[n];loop(n)cin>>a[i];
	int t,ans=0;cin>>t;
	loop(n){
		if(a[i]==t)ans+=10;
		else ans-=abs(a[i]-t);
	}
	cout<<ans<<endl;
	if(ans>0)cout<<"Happy"<<endl;
}